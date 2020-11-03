/*
 * GPIO_interrupt.c
 *
 *  Created on: 26 okt. 2020
 *      Author: Lowie Lameire
 */

#include "GPIO_interrupt.h"

void EINT3_IRQHandler() {

	if (((LPC_GPIOINT->IO0IntStatR >> 18) & 1) == 1) {
		RFID_lockHandler(); //tag doesn't have to be saved => param = 0
		LPC_GPIOINT->IO0IntClr |= (1 << 18); //clear interrupt bit
		assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
	}

	JS_inputHandler();
}
