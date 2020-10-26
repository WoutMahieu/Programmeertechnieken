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

void EINT3_IRQHandler();

#endif /* GPIO_INTERRUPT_H_ */
