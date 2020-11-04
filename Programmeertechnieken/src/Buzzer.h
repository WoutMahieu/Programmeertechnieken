/*
 * Buzzer.h
 *
 *  Created on: 26 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "lpc17xx.h"

void Buzzer_Init(void);
void Buzzer_Enable(void);
void Buzzer_Disable(void);
void Buzzer_Frequency(uint8_t f);

#endif /* BUZZER_H_ */
