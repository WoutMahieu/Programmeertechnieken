/*
 * InputControl.c
 *
 *  Created on: 8 nov. 2020
 *      Author: Lowie Lameire
 */


#include "InputControl.h"

int InputControl_CheckJSLeft(){
	if(Joystick_GetFlags() == 1){
		Joystick_SetFlags(0);
		return 1;
	}else{
		return 0;
	}
}

int InputControl_CheckJSCenter(){
	if(Joystick_GetFlags() == 2){
		Joystick_SetFlags(0);
		return 1;
	}else{
		return 0;
	}
}

int InputControl_CheckJSDown(){
	if(Joystick_GetFlags() == 4){
		Joystick_SetFlags(0);
		return 1;
	}else{
		return 0;
	}
}

int InputControl_CheckJSUp(){
	if(Joystick_GetFlags() == 8){
		Joystick_SetFlags(0);
		return 1;
	}else{
		return 0;
	}
}

int InputControl_CheckJSRight(){
	if(Joystick_GetFlags() == 16){
		Joystick_SetFlags(0);
		return 1;
	}else{
		return 0;
	}
}

int InputControl_CheckCS(){
	return ContactSwitch_GetFlag();
}

void InputControl_ModeRFID(int m){
	RFID_SetMode(m);
}

int InputControl_CheckRFID(){
	return RFID_GetBool();
}

int InputControl_CheckRFIDFalseTries(){
	return RFID_GetFalseTries();
}

void InputControl_SetRFIDFalseTries(int ft){
	RFID_SetFalseTries(ft);
}

void InputControl_EnableJoystick(){
	Joystick_Enable();
}

void InputControl_DisableJoystick(){
	Joystick_Disable();
}
