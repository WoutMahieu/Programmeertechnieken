/*
 * UART.c
 *
 *  Created on: 13 okt. 2020
 *      Author: Lowie Lameire
 */

#include "UART.h"

char tag[SIZEOFDATA];
uint8_t dataRead = 0;
uint8_t IIR;

void UART_init(){

	//1. Power: set bit for PCUART 2
	LPC_SC->PCONP |= (1 << 24);

	//2. Peripheral clock: in PCLKSEL1 select PCLK_UART 2
	// On reset PCLK = CCLK/4 = 25MHz

	//3. Baud rate: set bit DLAB to enable access to registers DLL and DLM
	//PCLK = 25MHz
	//BR = 9600
	LPC_UART2->LCR |= (1 << 7);

	//Set DLest to 108 (DEC) = 6C (HEX)
	LPC_UART2->DLL = 0x6C;
	LPC_UART2->DLM = 0;

	//Set FDR (Fractional Divider Register) with MULVAL = 2 [4:7] and DIVADDVAL = 1 [0:3]
	//0010 0001
	LPC_UART2->FDR = 0x21;

	//Disable DLAB again
	LPC_UART2->LCR &= ~(1 << 7);

	//4. UART FIFO: enable FIFO
	LPC_UART2->FCR |= 1; //fifo enable

	//5. Pins: Select UART pins through PINSEL registers and pin modes through PINMODE registers
	LPC_PINCON->PINSEL0 |= (1 << 22); // p0.11: select RXD2 as pin function
	LPC_PINCON->PINMODE0 |= (1 << 23); // p0.11: neither pull-up nor pull-down

	//6. Interrupts
	LPC_UART2->IER |= 1; //enables the Receive Data Available interrupt
	NVIC_EnableIRQ(UART2_IRQn); //enable UART2 interrupts

	//8. Enable 8-bit character length
	LPC_UART2->LCR |= 3;
}

char UART_getCharacter(){
	//Wait if Receiver Data Ready is not empty in Line Status Register
	//while ((LPC_UART2->LSR & 1) == 0);

	//Receiver Buffer Register: contains the next received character to be read.
	return LPC_UART2->RBR;
}

void UART2_IRQHandler() {

	printf("IRQHandler reached\n");

	IIR = LPC_UART2->IIR;

	//Shifting out the interruptstatus bit
	IIR >>= 1;

	//Masking unnecessary
	IIR &= 0x07;

	//Check if interruptid = RDA (Receive Data Available)
	if(IIR == 0x02 && dataRead == 0){
		//used for debugging
		//printf("Data available\n");

		for(int i = 0; i < SIZEOFDATA; i++){
			tag[i] = UART_getCharacter();
			//used for debugging
			//printf("%c\n", tag[i]);
		}
		dataRead = 1;
		//clear fifo
		LPC_UART2->FCR |= (1 << 1);
	}
}

char * UART_getTag(){
	return tag;
}

uint8_t UART_getFlag(){
	return dataRead;
}

void UART_setFlag(uint8_t flag){
	dataRead = flag;
}
