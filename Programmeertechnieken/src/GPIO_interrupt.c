/*
 * GPIO_interrupt.c
 *
 *  Created on: 26 okt. 2020
 *      Author: Lowie Lameire
 */

#include "GPIO_interrupt.h"

void EINT3_IRQHandler() {

	if (((LPC_GPIOINT->IO0IntStatR >> 18) & 1) == 1) {
		//printf("Interrupted\n");
		RFID_LockHandler();
		LPC_GPIOINT->IO0IntClr |= (1 << 18); //clear interrupt bit
		assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
	}
	else{
		Joystick_InputHandler();
	}
}

void TIMER1_IRQHandler(){
	Delay_SetFlag(1);
	LPC_TIM1->IR |= 1; //clear interrupt
	assert(LPC_TIM1->IR == 0);
}
