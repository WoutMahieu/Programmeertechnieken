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

/**
* Returns the flag that that is set by a joystick input
* 00000001 = 1 = LEFT, 0000010 = 2 = CENTER, 00000100 = 4 = DOWN, 00001000 = 8 = UP, 00010000 = 16 = RIGHT
*
* @return  flag
*/
int Joystick_GetFlags();

/**
* Function used to reset the flag each time it has been read by the state machine
*
* @param joystickFlags  integer the set the flag to
*/
void Joystick_SetFlags(int joystickFlags);

/**
* Initialize hardware for joystick input
*/
void Joystick_Init();

/**
* Sets the boolean "enabled" high. This boolean is checked before the flag can be set via the joystick input
*/
void Joystick_Enable();

/**
* Sets the boolean "enabled" low. This boolean is checked before the flag can be set via the joystick input
*/
void Joystick_Disable();

/**
* Handles the interrupt, sets the flag
*/
void Joystick_InputHandler();


#endif /* JOYSTICK_H_ */
