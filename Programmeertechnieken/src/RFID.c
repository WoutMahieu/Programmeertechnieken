/*
 * RFID.c
 *
 *  Created on: 12 okt. 2020
 *      Author: Lowie Lameire
 */


#include "RFID.h"


char tag_checksum[SIZEOF_TAG_CHECKSUM];
char hexData[SIZEOF_TAG_CHECKSUM];
char tag[SIZEOF_TAG_ID];

void RFID_init(){
	//LED1 as indicator of Tag in range
	LPC_GPIO1->FIODIR |= (1 << 18); //select p1.18 (LED 1) and write 1 to make it an output

	//DIP 11 as an input
	LPC_GPIO0->FIODIR &= ~(1 << 18); //select p0.18 and write 0 to make it an input

	//enable pull-down (needed for mbed application board)
	LPC_PINCON->PINMODE1 |= (3 << 4); //p0.18

	LPC_GPIOINT->IO0IntEnR |= (1 << 18); //enable GPIO interrupts for p0.18

	NVIC_EnableIRQ(EINT3_IRQn); //enable External Interrupt 0 Interrupt
	//note: we use EINT3 instead of EINT0 (doesn't work?!): all GPIO interrupt are connected to EINT3 interrupt source
	//https://binaryupdates.com/gpio-in-cortex-m3-lpc1768-microcontroller/2/
}

void RFID_driveLED(){
	Wait_ms(200);

	//if tag is in range turn LED1 on, otherwise turn LED1 off;
	if(((LPC_GPIO0->FIOPIN >> 18) & 1) == 1){
		LPC_GPIO1->FIOSET |= (1 << 18);
	}
	else{
		LPC_GPIO1->FIOCLR |= (1 << 18);
	}
}

char* RFID_getTagAndCheckSum(char * uartData){
	//check for start of transmission (=0x02), otherwise data is discarded;
	if(uartData[0] == 0x02){
		//don't save start of transmission (= 0x02)
		for(int i = 0; i < SIZEOF_TAG_CHECKSUM; i++){
			tag_checksum[i] = uartData[i+1];
		}

		//printf("%s\n", data);
		return tag_checksum;

	}else{
		printf("WARNING: invalid data\n");

		for(int i = 0; i < SIZEOF_TAG_CHECKSUM; i++){
			tag_checksum[i] = '0';
		}
		return tag_checksum;
	}

}

char* RFID_convertASCIIHEX(char * data){

	for(int i = 0; i < SIZEOF_TAG_CHECKSUM; i++){
		if((data[i] >= '0') && (data[i] <= '9')){
			hexData[i] = data[i] - 48;
		}
		else if((data[i] >= 'A') && (data[i] <= 'F')){
			hexData[i] = data[i] - 55;
		}
	}
	return hexData;
}

int RFID_checkSum(char * hexData){
	char tempCheckSum1 = hexData[0];
	char tempCheckSum2 = hexData[1];

	for(int i = 2; i < 10; i += 2){
		tempCheckSum1 = tempCheckSum1^hexData[i];
	}

	for(int i = 3; i < 10; i += 2){
		tempCheckSum2 = tempCheckSum2^hexData[i];
	}

	//printf("temp1: %x\n temp2: %x\n", tempCheckSum1, tempCheckSum2);

	char calculatedCheckSum = (tempCheckSum1 << 4) + tempCheckSum2;
	//printf("calculatedCheckSum: %x\n", calculatedCheckSum);

	char receivedCheckSum = (hexData[10] << 4) + hexData[11];
	//printf("receivedCheckSum: %x\n", receivedCheckSum);


	if(calculatedCheckSum == receivedCheckSum){
		return 1;
	}
	else{
		return 0;
	}
}

char* RFID_getTag(char * tag_checksum){
	for(int i = 0; i < SIZEOF_TAG_ID; i++){
		tag[i] = tag_checksum[i];
	}
	return tag;
}

void RFID_dataHandler(int saveTag){
	char * uartData; //16 chars
	char * tag_checksum; //12 chars
	char * hexData; //12 chars
	char * tag; //10 chars

	printf("\nNEW TAG READ\n");

	//reading uartData (16 characters)
	UART_readData();

	//get uart data
	uartData = UART_getData();

	printf("RECEIVED DATA %s\n", uartData);

	//dump unneeded sent data (STX, CR, LF and ETX)
	tag_checksum = RFID_getTagAndCheckSum(UART_getData());

	printf("CLEANED DATA %s\n", tag_checksum);

	//convert received ASCII to HEX
	hexData = RFID_convertASCIIHEX(tag_checksum);

	printf("CONVERTED DATA ");
	for(int i = 0; i < SIZEOF_TAG_CHECKSUM; i++){
		printf("%x", hexData[i]);
	}
	printf("\n");

	//checksum incorrect? Discard data
	if(RFID_checkSum(hexData) == 1){
		printf("Checksum is correct\n");

		//take checksum out of data so it can be saved
		tag = RFID_getTag(tag_checksum);
		printf("%s\n", tag);

		//if tag is in linkedlist
		//printf("Open door");

		if(saveTag == 1){
			//put tag in linked list
		}
		//if tag is in linked list open lock
	}
	//data is read, set flag low
	UART_setDataRead(0);
}


