/*
 * Delay.h
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "lpc17xx.h"

/*
 * Wait for an amount of seconds
 * @param t = seconds to wait
 */
void Wait_s(uint32_t t);

/*
 * Wait for an amount of miliseconds
 * @param t = miliseconds to wait
 */
void Wait_ms(uint32_t t);

/*
 * Wait for an amount of microseconds
 * @param t = microseconds to wait
 */
void Wait_us(uint32_t t);

/*
 * Start a timer for an amount of seconds (busy waiting)
 * @param t = amount of seconds
 */
void Delay_StartTime(uint32_t t);

/*
 * Set a flag to indicate that the timer is ready or not
 * @param f = flag
 */
void Delay_SetFlag(uint8_t f);

/*
 * Get the timer flag
 * @return the timer flag, '1' = ready, '0' = still running
 */
int Delay_GetFlag();

/*
 * Reset the timer
 */
void Delay_ResetTime();

/*
 * Check if the timer has started
 * @return '1' = running, '0' = not running
 */
int Delay_CheckTimerStarted();

#endif /* DELAY_H_ */
