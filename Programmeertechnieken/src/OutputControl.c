 /*
 * OutputControl.c
 *
 *  Created on: 06 Nov 2020
 *      Author: WoutMahieu
 */

#include "OutputControl.h"

void OutputControl_Lock(void){
	StatusLED_Red(0);
	StatusLED_Green(0);
	Buzzer_Disable();

	Lock_DriveLock(1);
	StatusLED_Blue(1);
}

void OutputControl_Unlock(void){
	StatusLED_Red(0);
	StatusLED_Blue(0);
	Buzzer_Disable();

	Lock_DriveLock(0);
	StatusLED_Green(1);
}

void OutputControl_Alarm(void){
	StatusLED_Red(1);
	Buzzer_Frequency(2500);
	Buzzer_Enable();
}
