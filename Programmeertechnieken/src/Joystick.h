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

int getJSFlags();

void setJSFlags(int joystickFlags);

void JS_init();

void JS_enable();

void JS_disable();

void JS_inputHandler();


#endif /* JOYSTICK_H_ */
