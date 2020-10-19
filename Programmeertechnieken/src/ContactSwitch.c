/*
 * ContactSwitch.c
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */
#include "ContactSwitch.h"

void ContactSwitch_Init(void){
	LPC_GPIO1->FIODIR &= ~(1 << 31); //p1.31 = Input (DIP20)
	LPC_GPIO1->FIOMASK &= ~(1 << 31);
}

uint8_t ContactSwitch_GetFlag(void){
	uint8_t flag = (uint8_t)((LPC_GPIO1->FIOPIN >> 31) & 0x01);
	return (flag);
}
