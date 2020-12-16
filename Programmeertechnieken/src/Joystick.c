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

int Joystick_GetFlags(){
	return joystickFlags;
}

void Joystick_SetFlags(int a){
	joystickFlags = a;
}

void Joystick_Enable(){
	enabled = 1;
}

void Joystick_Disable(){
	enabled = 0;
}

void Joystick_Init(){

	//Setting Joystick GPIO pins as inputs
	LPC_GPIO0->FIODIR &= ~(7 << 15); //select p0.15, p0.16 and p0.17 (JOYSTICK LEFT, CENTER and DOWN) and write 0 to make it an input
	LPC_GPIO0->FIODIR &= ~(3 << 23); //select p0.23 and p0.24 (JOYSTICK UP and RIGHT) and write 0 to make it an input

	//enable pull-down (needed for mbed application board)
	LPC_PINCON->PINMODE0 |= (3 << 30); //p0.15
	LPC_PINCON->PINMODE1 |= 15; //p0.16 and p0.17
	LPC_PINCON->PINMODE1 |= (15 << 14); //p0.23 and p0.24

	LPC_GPIOINT->IO0IntEnR |= (7 << 15); //enable GPIO interrupts for p0.15, p0.16 and p0.17 rising edge
	LPC_GPIOINT->IO0IntEnR |= (3 << 23); //enable GPIO interrupts for p0.23 and p0.24 rising edge

	NVIC_EnableIRQ(EINT3_IRQn); //enable External Interrupt 0 Interrupt
	//note: we use EINT3 instead of EINT0 (doesn't work?!): all GPIO interrupt are connected to EINT3 interrupt source
	//https://binaryupdates.com/gpio-in-cortex-m3-lpc1768-microcontroller/2/
}

void Joystick_InputHandler() {
	if(enabled == 1 && joystickFlags == 0){

		printf("Interrupt Joystick\n");

		//debounce: After the first edge, wait for a specific amount of time before reading the actual value.
		Wait_ms(200);

		//check interrupt status for p0.15 (LEFT) rising edge interrupt:
		if (((LPC_GPIOINT->IO0IntStatR >> 15) & 1) == 1) {
			joystickFlags = 1;
			LPC_GPIOINT->IO0IntClr |= (1 << 15); //Clear interrupt
			assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
		}

		//check interrupt status for p0.16 (CENTER) rising edge interrupt:
		else if(((LPC_GPIOINT->IO0IntStatR >> 16) & 1) == 1) {
			joystickFlags = 2;
			LPC_GPIOINT->IO0IntClr |= (1 << 16); //Clear interrupt
			assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
		}

		//check interrupt status for p0.17 (DOWN) rising edge interrupt:
		else if(((LPC_GPIOINT->IO0IntStatR >> 17) & 1) == 1) {
			joystickFlags = 4;
			LPC_GPIOINT->IO0IntClr |= (1 << 17); //Clear interrupt
			assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
		}

		//check interrupt status for p0.23 (UP) rising edge interrupt:
		else if(((LPC_GPIOINT->IO0IntStatR >> 23) & 1) == 1) {
			joystickFlags = 8;
			LPC_GPIOINT->IO0IntClr |= (1 << 23); //Clear interrupt
			assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
		}

		//check interrupt status for p0.24 (RIGHT) rising edge interrupt:
		else if(((LPC_GPIOINT->IO0IntStatR >> 24) & 1) == 1) {
			joystickFlags = 16;
			LPC_GPIOINT->IO0IntClr |= (1 << 24); //Clear interrupt
			assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
		}
	}
	else{
		LPC_GPIOINT->IO0IntClr |= (1 << 15); //Clear interrupts
		LPC_GPIOINT->IO0IntClr |= (1 << 16);
		LPC_GPIOINT->IO0IntClr |= (1 << 17);
		LPC_GPIOINT->IO0IntClr |= (1 << 23);
		LPC_GPIOINT->IO0IntClr |= (1 << 24);
		assert(LPC_GPIOINT->IO0IntClr == 0); //read the interrupt flag to make sure it has been set
	}
}

