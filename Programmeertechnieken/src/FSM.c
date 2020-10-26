/*
 * FSM.c
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#include "FSM.h"

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
			FSM_currentState = Forced;
			FSM_EnterForced();
		}
		break;
	case Opened:
		FSM_Opened();
	case Forced:
		FSM_Forced();

		if(ContactSwitch_GetFlag()){
			FSM_ExitForced();
			FSM_currentState = Locked;
			FSM_EnterLocked();
		}
	}
}

void FSM_Init(void){
	LCD_Init();
	LCD_autoUpdate = 0;
	LCD_Print("Initializing");
	LCD_Update();

	ContactSwitch_Init();
}

void FSM_ExitInit(void){
	LCD_Clear();
}

void FSM_EnterLocked(void){
	DisplayControl_LockedScreen();
}

void FSM_Locked(void){

}

void FSM_ExitLocked(void){
	LCD_Clear();
}

void FSM_EnterOpened(void){
	DisplayControl_OpenedScreen();
}

void FSM_Opened(void){

}

void FSM_ExitOpened(void){
	LCD_Clear();
}

void FSM_EnterForced(void){
	DisplayControl_AlarmScreen();
}

void FSM_Forced(void){

}

void FSM_ExitForced(void){
	LCD_Clear();
}

void FSM_EnterConfig(void){

}

void FSM_Condig(void){

}

void FSM_ExitConfig(void){

}
