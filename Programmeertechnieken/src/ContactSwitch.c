/*
 * ContactSwitch.c
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */
#include "ContactSwitch.h"

void ContactSwitch_Init(void){
	LPC_PINCON->PINMODE3 |= (3 << 28); //pull down resistor on the pin
	LPC_GPIO1->FIODIR &= ~(1 << 30); //pin =input
}

uint8_t ContactSwitch_GetFlag(void){
	return (uint8_t)((LPC_GPIO1->FIOPIN >> 30) & 0x1);
}
