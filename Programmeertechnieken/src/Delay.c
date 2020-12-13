/*
 * Delay.c
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#include "Delay.h"

const uint32_t PCLK = 25000000; //CCLK/4 = 25 MHz

void Wait_s(uint32_t t) {
	LPC_TIM0->TCR = (1 << 1); //Reset
	LPC_TIM0->MCR = (3 << 1); //Stop & reset on match
	LPC_TIM0->MR0 = t * PCLK; //match on t s
	LPC_TIM0->TCR = 1; //enable Timer0

	while (LPC_TIM0->TCR == 1){} //wait for the match to be reached
}

void Wait_ms(uint32_t t) {
	LPC_TIM0->TCR = (1 << 1); //Reset
	LPC_TIM0->MCR = (3 << 1); //Stop & reset on match
	LPC_TIM0->MR0 = t * 0.001 * PCLK; //match on t ms
	LPC_TIM0->TCR = 1; //enable Timer0

	while (LPC_TIM0->TCR == 1){} //wait for the match to be reached
}

void Wait_us(uint32_t t) {
	LPC_TIM0->TCR = (1 << 1); //Reset
	LPC_TIM0->MCR = (3 << 1); //Stop & reset on match
	LPC_TIM0->MR0 = t * 0.000001 * PCLK; //match on t µs
	LPC_TIM0->TCR = 1; //enable Timer0

	while (LPC_TIM0->TCR == 1){} //wait for the match to be reached
}

int timerReady = 0;

void Delay_StartTime(uint32_t t){
	LPC_TIM1->TCR = (1 << 1); //Reset
	LPC_TIM1->MCR = 1;	//interrupt on match
	LPC_TIM1->MR0 = t * PCLK; //match t on s
	LPC_TIM1->TCR = 1; //enable Timer1
	NVIC_EnableIRQ(TIMER1_IRQn);
}

void Delay_SetFlag(uint8_t f){
	timerReady = f;
}

int Delay_GetFlag(){
	return timerReady;
}

void Delay_ResetTime(){
	LPC_TIM1->TCR &= ~1; //stop the timer
	LPC_TIM1->TCR = (1 << 1); //Reset the timer
	timerReady = 0;
}

int Delay_CheckTimerStarted(){
	return (LPC_TIM1->TCR & 0x1);
}
