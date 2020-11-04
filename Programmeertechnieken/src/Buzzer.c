/*
 * Buzzer.c
 *
 *  Created on: 26 Oct 2020
 *      Author: WoutMahieu
 */

#include "Buzzer.h"

void Buzzer_Init(void){
	LPC_PINCON->PINSEL4 |= (1 << 0); //select buzzer for PWM1.1
	LPC_PWM1->PCR |= (1 << 9); //enable PWM1, single edge
	LPC_PWM1->PR = 249; //fpwm = 100 kHz
	LPC_PWM1->MCR = (1 << 1); //reset on match

	LPC_PWM1->MR1 = 50; //50% duty cycle
	LPC_PWM1->LER |= (1 << 1); //load MR1

	LPC_PWM1->TCR |= (1 << 3); //enable PWM mode
}

void Buzzer_Enable(void){
	LPC_PWM1->TCR |= (1 << 0);
}

void Buzzer_Disable(void){
	LPC_PWM1->TCR &= ~(1 << 0);
}

void Buzzer_Frequency(uint8_t f){
	LPC_PWM1->MR0 = 100000 / f; //set PWM rate (1kHz)
	LPC_PWM1->LER = (1 << 0); //load MR0
}
