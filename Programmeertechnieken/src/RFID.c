/*
 * RFID.c
 *
 *  Created on: 12 okt. 2020
 *      Author: Lowie Lameire
 */


#include "RFID.h"

// + 1 for the end of string char '/0'
char receivedData[SIZEOF_UART_DATA + 1] = {0};
char checksumData[SIZEOF_TAG_CHECKSUM + 1] = {0};
char hexData[SIZEOF_TAG_CHECKSUM + 1] = {0};
char tagID[SIZEOF_TAG_ID + 1] = {0};

char* firstTag = "6700999FF2";

int boolRFID = 0;

int mode = 0;
int falseTries = 0;

//list of valid/added tags
LinkedList_t* startPtrRFID = NULL;

void RFID_Init(){
	//LED1 as indicator of Tag in range
	LPC_GPIO1->FIODIR |= (1 << 18); //select p1.18 (LED 1) and write 1 to make it an output

	//select DIP 11 (p0.18) and write 0 to make it an input
	LPC_GPIO0->FIODIR &= ~(1 << 18);

	//enable pull-down (needed for mbed application board) for p0.18
	LPC_PINCON->PINMODE1 |= (3 << 4);

	//enable GPIO interrupts for p0.18
	LPC_GPIOINT->IO0IntEnR |= (1 << 18);

	//adding a tag so there can be tags added or deleted
	RFID_AddTagLL(firstTag);

	NVIC_EnableIRQ(EINT3_IRQn); //enable External Interrupt 0 Interrupt
	//note: we use EINT3 instead of EINT0 (doesn't work?!): all GPIO interrupt are connected to EINT3 interrupt source
	//https://binaryupdates.com/gpio-in-cortex-m3-lpc1768-microcontroller/2/
}

void RFID_SetMode(int m){
	mode = m;
}

void RFID_AddTag(){

	UART_ClearFIFO();
	RFID_DataHandler();

	if(strcmp(tagID, "") != 0){
		RFID_AddTagLL(tagID);
	}

	//setting flag so new UART can be read
	UART_SetDataRead(0);
}

void RFID_DeleteTag(const char* toDelete){
	LinkedL_Delete(&startPtrRFID, toDelete);
}

void RFID_DriveLED(){
	Wait_ms(200);

	//if tag is in range turn LED1 on, otherwise turn LED1 off;
	if(((LPC_GPIO0->FIOPIN >> 18) & 1) == 1){
		LPC_GPIO1->FIOSET |= (1 << 18);
	}
	else{
		LPC_GPIO1->FIOCLR |= (1 << 18);
	}
}

const char* RFID_GetTagAndCheckSumData(const char * uartData){
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

	}

	return checksumData;
}

const char* RFID_ConvertASCIIHEX(const char * asciiData){
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

int RFID_CheckSum(const char * hexData){
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

const char* RFID_GetTagID(const char * tagChecksum){

	//copy the first 10 chars of tagChecksum into tagID
	memcpy(tagID, tagChecksum, SIZEOF_TAG_ID);
	return tagID;
}

void RFID_DataHandler(){
	//for debugging purposes
	printf("-----------------------------------------------------------\n");

	printf("NEW TAG READ\n");
	//reading uartData (16 characters)
	UART_ReadData();

	//get uart data
	strcpy(receivedData,  UART_GetData());
	printf("RECEIVED DATA %s\n", receivedData);

	//go further if received data is valid
	if(strcmp(receivedData, "") != 0){

		//dump unneeded sent data (STX, CR, LF and ETX)
		strcpy(checksumData, RFID_GetTagAndCheckSumData(receivedData));
		printf("CLEANED DATA %s\n", checksumData);

		//convert received ASCII to HEX
		strcpy(hexData, RFID_ConvertASCIIHEX(checksumData));

		printf("CONVERTED DATA ");
		for(int i = 0; i < SIZEOF_TAG_CHECKSUM; i++){
			printf("%x", hexData[i]);
		}
		printf("\n");

		//checksum incorrect? return array of '0'
		if(RFID_CheckSum(hexData) == 1){
			printf("Checksum is correct\n");

			//take checksum out of data so it can be saved
			RFID_GetTagID(checksumData);
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

void RFID_LockHandler(){

	RFID_DataHandler();

	if(strcmp(tagID, "") != 0){
		const char* tagLockHandler = tagID;

		printf("tagLockHandler: %s\n", tagLockHandler);

		//check mode
		switch(mode){
			case 0:
			default:
				if(RFID_ContainsTagLL(tagLockHandler) == 1){
					printf("Tag is valid, lock opened\n");
					boolRFID = 1;

					//Flash LED
					StatusLED_Flash();
				}else{
					printf("Tag is invalid, lock stays closed\n");
					falseTries++;
				}
				break;
			case 1:
				RFID_AddTagLL(tagID);
				break;
			case 2:
				RFID_DeleteTagLL(tagID);
				break;
		}

		RFID_PrintLL();
	}
	else{
		printf("Received data was invalid\n");
	}
	//setting flag so new UART can be read
	UART_SetDataRead(0);
}

void RFID_AddTagLL(const char* tag){
	LinkedL_Push(&startPtrRFID, tag);
}

void RFID_DeleteTagLL(const char* tag){
	LinkedL_Delete(&startPtrRFID, tag);
}

int RFID_ContainsTagLL(const char* tag){
	return LinkedL_Contains(&startPtrRFID, tag);
}

void RFID_PrintLL(){
	LinkedL_PrintList(startPtrRFID);
}

LinkedList_t* RFID_GetLL(){
	return startPtrRFID;
}

int RFID_GetBool(){
	int temp = boolRFID;
	boolRFID = 0;
	return temp;
}

int RFID_GetFalseTries(void){
	return falseTries;
}

void RFID_SetFalseTries(int ft){
	falseTries = ft;
}

