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

void UART_init();

char UART_getCharacter();

void UART_readData();

char * UART_getData();

#endif /* UART_H_ */
