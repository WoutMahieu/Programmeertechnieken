/*
 * Timer.c
 *
 *  Created on: 18 Nov 2020
 *      Author: WoutMahieu
 */

#include "Timer.h"

void Timer_StartTimer(uint32_t t){
	Delay_StartTime(t);
}

int Timer_CheckTimer(){
	return Delay_GetFlag();
}

void Timer_StopTimer(){
	Delay_ResetTime();
}

int Timer_CheckTimerStarted(){
	return Delay_CheckTimerStarted();
}
