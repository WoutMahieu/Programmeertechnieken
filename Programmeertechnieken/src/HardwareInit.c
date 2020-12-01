/*
 * HardwareInit.c
 *
 *  Created on: 8 nov. 2020
 *      Author: Lowie Lameire
 */

#include "HardwareInit.h"


void HardwareInit(){
	LCD_Init();
	LCD_autoUpdate = 0;
	DisplayControl_InitScreen();

	Buzzer_Init();
	ContactSwitch_Init();
	Lock_Init();
	UART_Init();
	RFID_Init();
	Joystick_Init();
	StatusLED_Init();
}
