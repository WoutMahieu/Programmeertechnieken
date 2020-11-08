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

		//Check contactswitch, if '1' => Locked, else => Opened
		if(0){
			FSM_ExitInit();
			FSM_currentState = Locked;
			FSM_EnterLocked();
		}
		else{
			FSM_ExitInit();
			FSM_currentState = Opened;
			FSM_EnterOpened();
		}

		break;
	case Locked:
		FSM_Locked();

		//Check contactswitch, if '1' => Forced, else check for valid RFID: if valid => Opened else nothing

		break;
	case Opened:
		FSM_Opened();

		//Check for valid RFID: if valid => Locked else check for joystick center => Config
		if(0){
			FSM_ExitOpened();
			FSM_CurrentState = Locked;
			FSM_EnterLocked();
		}
		else if(0){
			FSM_ExitOpened();
			FSM_CurrentState = Config;
			FSM_EnterConfig();
		}

		break;
	case Forced:
		FSM_Forced();

		//Check if valid tag scanned, if !valid => nothing, else check contactswitch, if '1' => Locked, else => Opened
		if(0){
			if(0){
				FSM_ExitForced();
				FSM_CurrentState = Locked;
				FSM_EnterLocked();
			}
			else{
				FSM_ExitForced();
				FSM_CurrentState = Opened;
				FSM_EnterOpened();
			}
		}

		break;
	case Config:
		FSM_Config();

		//Check for joystick center => Opened
		break;
	}
}

void FSM_Init(void){
	//Init all hardware & show initialization message on screen !!!! set LCD_autoUpdate = 0; !!!!
	Hardware_Init();
}

void FSM_ExitInit(void){}

void FSM_EnterLocked(void){
	//Display locked screen & lock
	DisplayControl_LockedScreen();
}

void FSM_Locked(void){}

void FSM_ExitLocked(void){}

void FSM_EnterOpened(void){
	//Display opened screen & unlock
	DisplayControl_OpenedScreen();
	OutputControl_Unlock();
}

void FSM_Opened(void){}

void FSM_ExitOpened(void){}

void FSM_EnterForced(void){
	//Display alarm screen & activate alarm
	DisplayControl_AlarmScreen();
	OutputControl_Alarm();
}

void FSM_Forced(void){}

void FSM_ExitForced(void){}

void FSM_EnterConfig(void){
	//Show config screen
}

void FSM_Config(void){
	//Handle joystick input & add/remove RFID tags, depending on mode
}

void FSM_ExitConfig(void){}
