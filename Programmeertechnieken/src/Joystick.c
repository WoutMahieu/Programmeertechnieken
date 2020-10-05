/*
 * Joystick.c
 *
 *  Created on: 5 okt. 2020
 *      Author: Lowie Lameire
 */

#include "Joystick.h"

/*
 * 00000001 = 1 = LEFT
 * 00000010 = 2 = CENTER
 * 00000100 = 4 = DOWN
 * 00001000 = 8 = UP
 * 00010000 = 16 = RIGHT
 */

uint8_t joystickFlags = 0;
uint8_t enabled = 0;

int getJSFlags(){
	return joystickFlags;
}

void setJSFlags(int a){
	joystickFlags = a;
}

void JS_enable(){
	enabled = 1;
}

void JS_disable(){
	enabled = 0;
}

void JS_init(){

	//Setting joystic GPIO pins as inputs
	LPC_GPIO0->FIODIR &= ~(7 << 15); //select p0.15, p0.16 and p0.17 (JOYSTICK LEFT, CENTER and DOWN) and write 0 to make it an input
	LPC_GPIO0->FIODIR &= ~(3 << 23); //select p0.23 and p0.24 (JOYSTICK UP and RIGHT) and write 0 to make it an input

	//enable pull-down (needed for mbed application board)
	LPC_PINCON->PINMODE0 |= (3 << 30); //p0.15
	LPC_PINCON->PINMODE1 |= 15; //p0.16 and p0.17
	LPC_PINCON->PINMODE1 |= (15 << 14); //p0.23 and p0.24

	//enable GPIO interrupts rising edge
	LPC_GPIOINT->IO0IntEnR |= (7 << 15); //p0.15, p0.16 and p0.17
	LPC_GPIOINT->IO0IntEnR |= (3 << 23); //p0.23 and p0.24

	//enable External Interrupt 0 Interrupt
	NVIC_EnableIRQ(EINT3_IRQn);
	//note: we use EINT3 instead of EINT0 (doesn't work?!): all GPIO interrupt are connected to EINT3 interrupt source
	//https://binaryupdates.com/gpio-in-cortex-m3-lpc1768-microcontroller/2/
}

void approx_wait(uint32_t milliseconds) {
	//keep the processor busy approximately for a given time
	for (uint32_t j = 0; j < milliseconds; j++) {
		for (volatile uint32_t i = 0; i < 7320; i++);
	}
}

void EINT3_IRQHandler() {
	if(enabled == 1){

		//debounce: After the first edge, wait for a specific amount of time before reading the actual value.
			approx_wait(200);

		//check interrupt status for p0.15 rising edge interrupt:
			if (((LPC_GPIOINT->IO0IntStatR >> 15) & 1) == 1) {
				joystickFlags = 1;
				LPC_GPIOINT->IO0IntClr |= (1 << 15); //
				assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
			}

			//check interrupt status for p0.16 rising edge interrupt:
			else if(((LPC_GPIOINT->IO0IntStatR >> 16) & 1) == 1) {
				joystickFlags = 2;
				LPC_GPIOINT->IO0IntClr |= (1 << 16); //
				assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
			}

			//check interrupt status for p0.16 rising edge interrupt:
			else if(((LPC_GPIOINT->IO0IntStatR >> 17) & 1) == 1) {
				joystickFlags = 4;
				LPC_GPIOINT->IO0IntClr |= (1 << 17); //
				assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
			}

			//check interrupt status for p0.16 rising edge interrupt:
			else if(((LPC_GPIOINT->IO0IntStatR >> 23) & 1) == 1) {
				joystickFlags = 8;
				LPC_GPIOINT->IO0IntClr |= (1 << 23); //
				assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
			}

			//check interrupt status for p0.16 rising edge interrupt:
			else if(((LPC_GPIOINT->IO0IntStatR >> 24) & 1) == 1) {
				joystickFlags = 16;
				LPC_GPIOINT->IO0IntClr |= (1 << 24); //
				assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
			}
	}
}

