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

#define SIZEOFDATA 16

void UART_init();

char UART_getCharacter();

void UART0_IRQHandler();

char * UART_getTag();

uint8_t UART_getFlag();

void UART_setFlag(uint8_t);

#endif /* UART_H_ */
