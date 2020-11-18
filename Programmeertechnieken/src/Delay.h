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
uint8_t Delay_CheckTime();
void Delay_StopTime();

#endif /* DELAY_H_ */
