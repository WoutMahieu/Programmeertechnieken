/*
 * SSP.c
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#include "SSP.h"
#include "lpc17xx.h"

void SSP_Init(){
	//Power
	LPC_SC->PCONP |= (1 << 10);

	//Clock
	LPC_SC->PCLKSEL0 |= (1 << 20); //SSP_PCLK = CCLK = 100MHz
	LPC_SSP1->CPSR |= 6; //Clock PreScale Register

	//Pin config
	LPC_PINCON->PINSEL0 |= (2 << 18); //p5 = MOSI1
	LPC_PINCON->PINSEL0 &= ~(3 << 16); //p6 = RESET
	LPC_GPIO0->FIODIR |= (1 << 8);
	LPC_PINCON->PINSEL0 |= (2 << 14); //p7 = SCK1
	LPC_PINCON->PINSEL0 |= (2 << 12); //p8 = SSEL1 (A0)
	LPC_PINCON->PINSEL1 &= ~(3 << 4); //p11 = nCS
	LPC_GPIO0->FIODIR |= (1 << 18);

	//RESET, A0 & nCS = high
	LPC_GPIO0->FIOSET |= (1 << 8) | (1 << 6) | (1 << 18);

	//SSP1 Control Register 1
	LPC_SSP1->CR0 |= 7; //8 bit data transfer
	LPC_SSP1->CR0 &= ~(3 << 4); //SPI frame format
	LPC_SSP1->CR0 |= (1 << 6); //SCK1 high between frames
	LPC_SSP1->CR0 |= (1 << 7); //capture on transition back to inter-frame state of SCK1
	LPC_SSP1->CR0 &= ~(0xFF << 8); //PCLK / (CPSDVSR * [SCR+1]) & PCLK = CCLK, CPSR = 6 => SCK = 16 MHz

	//SSP1 Control Register 0
	LPC_SSP1->CR1 &= ~1; //No loopback
	LPC_SSP1->CR1 |= (1 << 1); //SSP enabled
	LPC_SSP1->CR1 &= ~(1 << 2); //Master

	//SSP1 Interrupt Mask Set/Clear register
	LPC_SSP1->IMSC |= 1; //enable interrupt on receive overrun
	LPC_SSP1->IMSC |= (1 << 1); //enable interrupt on receive time-out
}

uint8_t SSP_Write(uint8_t data){
	while(!(LPC_SSP1->SR & (1 << 1))){} //wait for space in the Tx FIFO

	LPC_GPIO0->FIOCLR |= (1 << 18); //select the slave
	Wait_us(5);

	LPC_SSP1->DR = data; //send data

	//receive data
	while(!(LPC_SSP1->SR & (1 << 2))){} //wait until Rx FIFO not empty

	LPC_GPIO0->FIOSET |= (1 << 18); //release the slave

	return LPC_SSP1->DR && 0xFF; //return the received data
}
