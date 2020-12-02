/*
 * Delay.h
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef DELAY_H_
#define DELAY_H_

#include "lpc17xx.h"

void Wait_s(uint32_t t);
void Wait_ms(uint32_t t);
void Wait_us(uint32_t t);

void Delay_StartTime(uint32_t t);
void Delay_SetFlag(uint8_t f);
int Delay_GetFlag();
void Delay_ResetTime();
int Delay_CheckTimerStarted();

#endif /* DELAY_H_ */
