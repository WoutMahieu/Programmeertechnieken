/*
 * RFID.h
 *
 *  Created on: 12 okt. 2020
 *      Author: Lowie Lameire
 */

#ifndef RFID_H_
#define RFID_H_

#include "LPC17xx.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "Delay.h"
#include "UART.h"
#include "GPIO_interrupt.h"

#define SIZEOF_TAG_CHECKSUM 12
#define SIZEOF_TAG_ID 10

void RFID_init();
void RFID_driveLED();

char* RFID_getTagAndCheckSum(char * uartData);
char* RFID_convertASCIIHEX(char * data);
int RFID_checkSum(char * data);
char* RFID_getTag(char * hexData);
void RFID_dataHandler(int saveTag);


#endif /* RFID_H_ */
