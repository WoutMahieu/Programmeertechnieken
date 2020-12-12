/*
 * GPIO_interrupt.h
 *
 *  Created on: 26 okt. 2020
 *      Author: Lowie Lameire
 */

#ifndef GPIO_INTERRUPT_H_
#define GPIO_INTERRUPT_H_

#include "LPC17xx.h"
#include <assert.h>

#include "Joystick.h"
#include "RFID.h"
#include "Delay.h"

/**
* Interrupt handler:
* handles the interrupt that is caused when a RFID-tag is in range of the RFID-reader
* handles interrupts caused by the joystick
*/
void EINT3_IRQHandler();
void TIMER1_IRQHandler();

#endif /* GPIO_INTERRUPT_H_ */
