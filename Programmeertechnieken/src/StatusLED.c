/*
 * StatusLED.c
 *
 *  Created on: 06 Nov 2020
 *      Author: WoutMahieu
 */

#include "StatusLED.h"

void StatusLED_Init(void){
	//GPIO
	LPC_GPIO2->FIODIR |= (7 << 1); //direction = out
	LPC_GPIO2->FIOSET |= (7 << 1); //turn off all leds (= pins on)
}

void StatusLED_Red(int bool){
	if(bool == 1){
		LPC_GPIO2->FIOCLR |= (1 << 3);
	}
	else{
		LPC_GPIO2->FIOSET |= (1 << 3);
	}
}

void StatusLED_Green(int bool){
	if(bool == 1){
		LPC_GPIO2->FIOCLR |= (1 << 2);
	}
	else{
		LPC_GPIO2->FIOSET |= (1 << 2);
	}
}

void StatusLED_Blue(int bool){
	if(bool == 1){
		LPC_GPIO2->FIOCLR |= (1 << 1);
	}
	else{
		LPC_GPIO2->FIOSET |= (1 << 1);
	}
}

void StatusLED_Flash(){
	int temp = ~((LPC_GPIO2->FIOPIN >> 1) & 0x7);
	LPC_GPIO2->FIOSET |= (temp << 1);
	Wait_ms(250);
	LPC_GPIO2->FIOCLR |= (temp << 1);
}
