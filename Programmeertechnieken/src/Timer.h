/*
 * Timer.h
 *
 *  Created on: 18 Nov 2020
 *      Author: WoutMahieu
 */

#ifndef TIMER_H_
#define TIMER_H_

#include "Delay.h"

/*
 * Start the timer for an amount of seconds
 * @param t = amount of seconds
 */
void Timer_StartTimer(uint32_t t);

/*
 * Check if the timer is ready
 * @return '1' if ready, '0' if still running
 */
int Timer_CheckTimer(void);

/*
 * Stop & reset the timer
 */
void Timer_StopTimer(void);

/*
 * Check if the timer is already running
 * @return '1' if running, '0' if not running
 */
int Timer_CheckTimerStarted(void);

#endif /* TIMER_H_ */
