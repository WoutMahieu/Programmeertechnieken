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
#include "LinkedList.h"
#include "Joystick.h"

#define SIZEOF_TAG_CHECKSUM 12
#define SIZEOF_TAG_ID 10

void RFID_init();

void RFID_driveLED();

const char* RFID_getTagAndCheckSumData(const char * uartData);
const char* RFID_convertASCIIHEX(const char * data);
int RFID_checkSum(const char * data);
const char* RFID_getTagData(const char * hexData);
const char* RFID_getTagID(const char * tag_checksum);
void RFID_dataHandler();

int RFID_lockHandler();
void RFID_addTag();

void RFID_addTagLL(const char* tag);
const char* RFID_deleteTagLL(const char* tag);
int RFID_containsTagLL(const char* tag);
void RFID_printLL();

#endif /* RFID_H_ */
