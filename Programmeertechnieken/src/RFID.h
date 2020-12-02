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
#include "InputControl.h"
#include "StatusLED.h"

#define SIZEOF_TAG_CHECKSUM 12
#define SIZEOF_TAG_ID 10

void RFID_Init(void);

void RFID_SetMode(int);

void RFID_DriveLED(void);

const char* RFID_GetTagAndCheckSumData(const char *);
const char* RFID_ConvertASCIIHEX(const char *);
int RFID_CheckSum(const char *);
const char* RFID_GetTagID(const char *);

void RFID_DataHandler(void);
void RFID_LockHandler(void);

void RFID_AddTag(void);
void RFID_DeleteTag(const char *);

void RFID_AddTagLL(const char *);
void RFID_DeleteTagLL(const char *);
int RFID_ContainsTagLL(const char *);
void RFID_PrintLL(void);

LinkedList_t* RFID_GetLL(void);

int RFID_GetBool(void);
int RFID_GetFalseTries(void);
void RFID_SetFalseTries(int);

#endif /* RFID_H_ */
