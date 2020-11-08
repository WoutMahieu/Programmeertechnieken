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

int Joystick_GetFlags();

void Joystick_SetFlags(int joystickFlags);

void Joystick_Init();

void Joystick_Enable();

void Joystick_Disable();

void Joystick_InputHandler();


#endif /* JOYSTICK_H_ */
