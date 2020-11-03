/*
 * RFID.c
 *
 *  Created on: 12 okt. 2020
 *      Author: Lowie Lameire
 */


#include "RFID.h"


//char tag_checksum[SIZEOF_TAG_CHECKSUM];
//char hexData[SIZEOF_TAG_CHECKSUM];
//char tag[SIZEOF_TAG_ID];

// + 1 for the end of string char '/0'
char receivedData[SIZEOF_UART_DATA + 1] = {0};
char checksumData[SIZEOF_TAG_CHECKSUM + 1] = {0};
char hexData[SIZEOF_TAG_CHECKSUM + 1] = {0};
char tagID[SIZEOF_TAG_ID + 1] = {0};

LinkedList_t* startPtrRFID = NULL;

void RFID_init(){
	//LED1 as indicator of Tag in range
	LPC_GPIO1->FIODIR |= (1 << 18); //select p1.18 (LED 1) and write 1 to make it an output

	//select DIP 11 (p0.18) and write 0 to make it an input
	LPC_GPIO0->FIODIR &= ~(1 << 18);

	//enable pull-down (needed for mbed application board) for p0.18
	LPC_PINCON->PINMODE1 |= (3 << 4);

	//enable GPIO interrupts for p0.18
	LPC_GPIOINT->IO0IntEnR |= (1 << 18);

	NVIC_EnableIRQ(EINT3_IRQn); //enable External Interrupt 0 Interrupt
	//note: we use EINT3 instead of EINT0 (doesn't work?!): all GPIO interrupt are connected to EINT3 interrupt source
	//https://binaryupdates.com/gpio-in-cortex-m3-lpc1768-microcontroller/2/
}

void RFID_addTag(){

	//DIP 11 as an output so there can't be an interrupt triggered
	LPC_GPIO0->FIODIR |= (1 << 18); //select p0.18 and write 0 to make it an input

	printf("Bring your tag in range of the RFID reader within the upcoming 5 seconds\n");
	UART_clearFIFO();
	Wait_s(5);
	RFID_dataHandler();

	if(strcmp(tagID, "") != 0){
		RFID_addTagLL(tagID);
	}

	//DIP 11 as an input
	LPC_GPIO0->FIODIR &= ~(1 << 18);
	//setting flag so new UART can be read
	UART_setDataRead(0);
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

const char* RFID_getTagAndCheckSumData(const char * uartData){
	//check for start of transmission (=0x02), otherwise data is discarded;
	if(uartData[0] == 0x02){
		//don't save start of transmission (= 0x02)
		for(int i = 0; i < 12; i++){
			checksumData[i] = uartData[i+1];
		}

		//for debugging purposes
		//printf("STRLEN: %d\n", strlen(tag_checksum));

		//for debugging purposes
		//printf("RFID_getTagAndCheckSumData: %s\n", tag_checksum);

	}else{
		printf("WARNING: invalid data\n");
		//checksumData[0] = '';
	}
	return checksumData;
}

const char* RFID_convertASCIIHEX(const char * asciiData){
	for(int i = 0; i < SIZEOF_TAG_CHECKSUM; i++){
		if((asciiData[i] >= '0') && (asciiData[i] <= '9')){
			hexData[i] = asciiData[i] - 48;
		}
		else if((asciiData[i] >= 'A') && (asciiData[i] <= 'F')){
			hexData[i] = asciiData[i] - 55;
		}
	}
	//for debugging purposes
//	for(int i = 0; i < SIZEOF_TAG_CHECKSUM; i++){
//			printf("%x", hexData[i]);
//	}
	//printf("\n");
	return hexData;
}

int RFID_checkSum(const char * hexData){
	char tempCheckSum1 = hexData[0];
	char tempCheckSum2 = hexData[1];

	for(int i = 2; i < 10; i += 2){
		tempCheckSum1 = tempCheckSum1^hexData[i];
	}

	for(int i = 3; i < 10; i += 2){
		tempCheckSum2 = tempCheckSum2^hexData[i];
	}

	//for debugging purposes
	//printf("temp1: %x\n temp2: %x\n", tempCheckSum1, tempCheckSum2);

	char calculatedCheckSum = (tempCheckSum1 << 4) + tempCheckSum2;
	//for debugging purposes
	//printf("calculatedCheckSum: %x\n", calculatedCheckSum);

	char receivedCheckSum = (hexData[10] << 4) + hexData[11];
	//for debugging purposes
	//printf("receivedCheckSum: %x\n", receivedCheckSum);


	if(calculatedCheckSum == receivedCheckSum){
		return 1;
	}
	else{
		return 0;
	}
}

const char* RFID_getTagID(const char * tagChecksum){
	printf("RFID_getTagID: Before copying\n");
	RFID_printLL();

	memcpy(tagID, tagChecksum, SIZEOF_TAG_ID);

	printf("RFID_getTagID: After copying\n");
	RFID_printLL();
	//for debugging purposes
	//printf("RFID_getTagData: %s\n", tag);
	return tagID;
}

void RFID_dataHandler(){
	printf("-----------------------------------------------------------\n");

	printf("NEW TAG READ\n");
	//reading uartData (16 characters)
	UART_readData();

	//get uart data
	strcpy(receivedData,  UART_getData());
	printf("RECEIVED DATA %s\n", receivedData);

	//go further if received data is valid
	if(strcmp(receivedData, "") != 0){

		//dump unneeded sent data (STX, CR, LF and ETX)
		strcpy(checksumData, RFID_getTagAndCheckSumData(receivedData));
		printf("CLEANED DATA %s\n", checksumData);

		//convert received ASCII to HEX
		strcpy(hexData, RFID_convertASCIIHEX(checksumData));

		printf("CONVERTED DATA ");
		for(int i = 0; i < SIZEOF_TAG_CHECKSUM; i++){
			printf("%x", hexData[i]);
		}
		printf("\n");

		//checksum incorrect? return array of '0'
		if(RFID_checkSum(hexData) == 1){
			printf("Checksum is correct\n");

			printf("Datahandler: Before copying\n");
			RFID_printLL();

			//take checksum out of data so it can be saved
			RFID_getTagID(checksumData);

			printf("Datahandler: After copying\n");
			RFID_printLL();
		}
		printf("-----------------------------------------------------------\n");
	}
	else{
		printf("Received data is invalid\n");
		strcpy(receivedData, "");
		strcpy(checksumData, "");
		strcpy(hexData, "");
		strcpy(tagID, "");
	}
}

int RFID_lockHandler(){
	int lock = 0; //0 = closed, 1 = opened
	RFID_dataHandler();

	if(strcmp(tagID, "") != 0){
		const char* tagLockHandler = tagID;

		printf("tagLockHandler: %s\n", tagLockHandler);

		if(RFID_containsTagLL(tagLockHandler) == 1){
			printf("Tag is valid, lock opened\n");
			lock = 1;
		}else{
			printf("Tag is invalid, lock stays closed\n");
			lock = 0;
		}

		RFID_printLL();
	}
	else{
		printf("Received data was invalid\n");
	}

	//setting flag so new UART can be read
	UART_setDataRead(0);
	return lock;
}

void RFID_addTagLL(const char* tag){
	LinkedL_push(&startPtrRFID, tag);
}

const char* RFID_deleteTagLL(const char* tag){
	return LinkedL_delete(&startPtrRFID, tag);
}

int RFID_containsTagLL(const char* tag){
	return LinkedL_contains(&startPtrRFID, tag);
}

void RFID_printLL(){
	LinkedL_printList(startPtrRFID);
}
