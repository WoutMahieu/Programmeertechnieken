/*
 * Timer.h
 *
 *  Created on: 18 Nov 2020
 *      Author: WoutMahieu
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Delay.h"

void Timer_StartTimer(uint32_t t);
int Timer_CheckTimer();
void Timer_StopTimer();
int Timer_CheckTimerStarted();

#endif /* TIMER_H_ */
