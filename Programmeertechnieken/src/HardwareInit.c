/*
 * HardwareInit.c
 *
 *  Created on: 8 nov. 2020
 *      Author: Lowie Lameire
 */

#include "HardwareInit.h"


void HardwareInit(){
	Buzzer_Init();
	ContactSwitch_Init();
	DisplayControl_InitScreen();
	Joystick_Init();
	LCD_Init();
	Lock_Init();
	RFID_Init();
	SSP_Init();
	StatusLED_Init();
	UART_Init();
}
