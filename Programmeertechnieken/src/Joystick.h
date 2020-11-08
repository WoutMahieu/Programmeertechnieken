/*
 * Joystick.h
 *
 *  Created on: 5 okt. 2020
 *      Author: Lowie Lameire
 */

#ifndef JOYSTICK_H_
#define JOYSTICK_H_
#include "LPC17xx.h"
#include <assert.h>

#include "Delay.h"
#include "GPIO_interrupt.h"

int JS_getFlags();

void JS_SetFlags(int joystickFlags);

void JS_Init();

void JS_Enable();

void JS_Disable();

void JS_InputHandler();


#endif /* JOYSTICK_H_ */
