/*
 * FSM.c
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#include "FSM.h"
#include "LCD.h"
#include "ContactSwitch.h"
#include "Delay.h"

enum states {Init, Locked, Opened, Forced, Config};
enum states FSM_currentState = Init;

void FSM_UpdateStates(void){
	switch(FSM_currentState){
	case Init:
		FSM_Init();

		FSM_ExitInit();
		FSM_currentState = Locked;
		FSM_EnterLocked();
		break;
	case Locked:
		FSM_Locked();

		if(!ContactSwitch_GetFlag()){
			FSM_ExitLocked();
			FSM_currentState = Opened;
			FSM_EnterOpened();
		}
		break;
	case Opened:
		FSM_Opened();

		if(ContactSwitch_GetFlag()){
			FSM_ExitOpened();
			FSM_currentState = Locked;
			FSM_EnterLocked();
		}

	}
}

void FSM_Init(void){
	LCD_Print("Initializing");

	LCD_Init();
	ContactSwitch_Init();
}

void FSM_ExitInit(void){
	LCD_Clear();
}

void FSM_EnterLocked(void){
	LCD_Print("Locked");
}

void FSM_Locked(void){

}

void FSM_ExitLocked(void){
	LCD_Clear();
}

void FSM_EnterOpened(void){
	LCD_Print("Open");
}

void FSM_Opened(void){

}

void FSM_ExitOpened(void){
	LCD_Clear();
}

void FSM_EnterForced(void){

}

void FSM_Forced(void){

}

void FSM_ExitForced(void){

}

void FSM_EnterConfig(void){

}

void FSM_Condig(void){

}

void FSM_ExitConfig(void){

}
