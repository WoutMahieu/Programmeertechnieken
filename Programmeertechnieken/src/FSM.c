/*
 * FSM.c
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

/*-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 *-------------------------------------------------------------------------------------------------------------
 * TOE TE VOEGEN:
 * 3x verkeerde tag = alarm
 * Automatisch sluiten na x seconden toe => Geïmplementeerd, ongetest
 * Joystick enable -> InputControl_joystickenable
 */

#include "FSM.h"

enum states {Init, Locked, Opened, Forced, Config};
enum states FSM_CurrentState = Init;

void FSM_UpdateStates(void){
	switch(FSM_CurrentState){
	case Init:
		FSM_Init();

		//Check contactswitch, if '1' => Locked, else => Opened
		if(InputControl_CheckCS()){
			FSM_ExitInit();
			FSM_CurrentState = Locked;
			FSM_EnterLocked();
		}
		else{
			FSM_ExitInit();
			FSM_CurrentState = Opened;
			FSM_EnterOpened();
		}

		break;
	case Locked:
		FSM_Locked();

		//Check contactswitch, if '0' => Forced, else check for valid RFID: if valid => Opened else nothing
		if(!InputControl_CheckCS()){
			FSM_ExitLocked();
			FSM_CurrentState = Forced;
			FSM_EnterForced();
		}
		else if(InputControl_CheckRFID()){
			FSM_ExitLocked();
			FSM_CurrentState = Opened;
			FSM_EnterOpened();
		}

		break;
	case Opened:
		FSM_Opened();

		//Check for valid RFID: if valid => Locked else check for joystick center => Config else check for 10s passed & contactswitch = '1' => Locked
		if(InputControl_CheckRFID() && InputControl_CheckCS()){
			FSM_ExitOpened();
			FSM_CurrentState = Locked;
			FSM_EnterLocked();
		}
		else if(InputControl_CheckJSCenter()){
			FSM_ExitOpened();
			FSM_CurrentState = Config;
			FSM_EnterConfig();
		}
//		else if(InputControl_CheckCS()){
//			if(!Timer_CheckTimer()){
//				Timer_StartTimer(10);
//			}
//			else{
//				FSM_ExitOpened();
//				FSM_CurrentState = Locked;
//				FSM_EnterLocked();
//			}
//		}
//		else{
//			Timer_StopTimer();
//		}

		break;
	case Forced:
		FSM_Forced();

		//Check if valid tag scanned, if !valid => nothing, else check contactswitch, if '1' => Locked, else => Opened
		if(InputControl_CheckRFID()){
			if(InputControl_CheckCS()){
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
		if(InputControl_CheckJSCenter()){
			FSM_ExitConfig();
			FSM_CurrentState = Opened;
			FSM_EnterOpened();
		}

		break;
	}
}

void FSM_Init(void){
	//Init all hardware & show initialization message on screen !!!! set LCD_autoUpdate = 0; !!!!
	HardwareInit();

	//disable RFID
	//InputControl_DisableRFID();
}

void FSM_ExitInit(void){}

void FSM_EnterLocked(void){
	//Display locked screen & lock
	DisplayControl_LockedScreen();
	OutputControl_Lock();

	//enable RFID
	//InputControl_EnableRFID();
}

void FSM_Locked(void){}

void FSM_ExitLocked(void){
	//disable RFID
	//InputControl_DisableRFID();
}

void FSM_EnterOpened(void){
	//Display opened screen & unlock
	DisplayControl_OpenedScreen();
	OutputControl_Unlock();

	//enable joystick
	Joystick_Enable();
}

void FSM_Opened(void){}

void FSM_ExitOpened(void){
	//disable joystick
	Joystick_Disable();
}

void FSM_EnterForced(void){
	//Display alarm screen & activate alarm
	DisplayControl_AlarmScreen();
	OutputControl_Alarm();
}

void FSM_Forced(void){}

void FSM_ExitForced(void){}

void FSM_EnterConfig(void){
	//enable joystick
	Joystick_Enable();

	//Show config screen
	DisplayControl_MenuBuilder();

	//disable RFID interrupt
	InputControl_DisableRFID();
}

void FSM_Config(void){
	//Handle joystick input & add/remove RFID tags, depending on mode
	if(!Displaycontrol_ConfigScreen()){
		if(InputControl_CheckJSCenter()){
			//add tag
			InputControl_AddRFID();
		}
	}
	else{
		//remove tag
	}
}

void FSM_ExitConfig(void){
	//disable joystick
	Joystick_Disable();

	//enable RFID interrupt
	InputControl_EnableRFID();
}
