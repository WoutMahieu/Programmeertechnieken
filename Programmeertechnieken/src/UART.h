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

/*
* Initialize hardware so UART data can be read
*/
void UART_Init(void);

/*
* Returns the char from the Receiver Buffer Register
* @return  char from the Receiver Buffer Register
*/
char UART_GetCharacter(void);

/*
* Reads character by character out of the Receiver Buffer Register and stores the read data in the variable "uartData"
*/
void UART_ReadData(void);

/*
* Returns the value of the variable "uartData"
* @return  uartData
*/
const char * UART_GetData(void);

/*
* Function to reset the variable dataRead, it is a boolean that has to be 0 for the UART_ReadData to be able to read a new UART data.
*/
void UART_SetDataRead(int);

/*
* Function that clears the FIFO register that holds the character received via UART
*/
void UART_ClearFIFO(void);

#endif /* UART_H_ */
