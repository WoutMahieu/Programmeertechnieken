/*
 * Delay.c
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#include "Delay.h"

void Wait_s(uint32_t t) {
	const uint32_t PCLK = 25000000; //CCLK/4 = 25 MHz

	LPC_TIM0->TCR = (1 << 1); //Reset
	LPC_TIM0->MCR = (3 << 1); //Stop & reset on match
	LPC_TIM0->MR0 = t * PCLK; //match on t s
	LPC_TIM0->TCR = 1; //enable Timer0

	while (LPC_TIM0->TCR == 1){} //wait for the match to be reached
}

void Wait_ms(uint32_t t) {
	const uint32_t PCLK = 25000000; //CCLK/4 = 25 MHz

	LPC_TIM0->TCR = (1 << 1); //Reset
	LPC_TIM0->MCR = (3 << 1); //Stop & reset on match
	LPC_TIM0->MR0 = t * 0.001 * PCLK; //match on t ms
	LPC_TIM0->TCR = 1; //enable Timer0

	while (LPC_TIM0->TCR == 1){} //wait for the match to be reached
}

void Wait_µs(uint32_t t) {
	const uint32_t PCLK = 25000000; //CCLK/4 = 25 MHz

	LPC_TIM0->TCR = (1 << 1); //Reset
	LPC_TIM0->MCR = (3 << 1); //Stop & reset on match
	LPC_TIM0->MR0 = t * 0.000001 * PCLK; //match on t µs
	LPC_TIM0->TCR = 1; //enable Timer0

	while (LPC_TIM0->TCR == 1){} //wait for the match to be reached
}
