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
#include "RFID.h"

int InputControl_CheckJSCenter();
int InputControl_CheckJSDown();
int InputControl_CheckJSLeft();
int InputControl_CheckJSRight();
int InputControl_CheckJSUp();
int InputControl_CheckCS();
void InputControl_ModeRFID();
int InputControl_CheckRFID();
int InputControl_CheckRFIDFalseTries();
void InputControl_SetRFIDFalseTries(int);
void InputControl_AddRFID();
void InputControl_EnableJoystick();
void InputControl_DisableJoystick();

#endif /* INPUTCONTROL_H_ */
