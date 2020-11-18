/*
 * InputControl.h
 *
 *  Created on: 8 nov. 2020
 *      Author: Lowie Lameire
 */

#ifndef INPUTCONTROL_H_
#define INPUTCONTROL_H_

#include "Joystick.h"
#include "ContactSwitch.h"

int InputControl_CheckJSCenter();
int InputControl_CheckJSDown();
int InputControl_CheckJSLeft();
int InputControl_CheckJSRight();
int InputControl_CheckJSUp();
int InputControl_checkCS();

#endif /* INPUTCONTROL_H_ */
