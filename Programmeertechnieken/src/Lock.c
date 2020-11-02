/*
 * Lock.c
 *
 *  Created on: 24 okt. 2323
 *      Author: Lowie Lameire
 */

#include "Lock.h"

void Lock_init(){
	//select p1.23 (LED4) and write 1 to make it an output
	LPC_GPIO1->FIODIR |= (1 << 23);
}

void Lock_driveLock(int bool){
	if(bool == 1){
		//select p1.23 and write 1 to turn LED4 on
		LPC_GPIO1->FIOSET |= (1 << 23);
	}
	else{
		//select p1.23 and write 1 to turn LED4 off
		LPC_GPIO1->FIOCLR |= (1 << 23);
	}
}
