/*
 * UART.h
 *
 *  Created on: 13 okt. 2020
 *      Author: Lowie Lameire
 */

#ifndef UART_H_
#define UART_H_

#include <stdio.h>
#include "LPC17xx.h"

#define SIZEOF_UART_DATA 16

void UART_Init();

char UART_GetCharacter();

void UART_ReadData();

const char * UART_GetData();

void UART_SetDataRead();

void UART_ClearFIFO();

#endif /* UART_H_ */
