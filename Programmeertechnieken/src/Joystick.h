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

int getJSFlags();

void setJSFlags(int joystickFlags);

void JS_init();

void JS_enable();

void JS_disable();

void approx_wait(uint32_t milliseconds);

void EINT3_IRQHandler();


#endif /* JOYSTICK_H_ */
