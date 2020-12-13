/*
 * Buzzer.h
 *
 *  Created on: 26 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef BUZZER_H_
#define BUZZER_H_

#include "lpc17xx.h"

/*
 * Initialize buzzer
 */
void Buzzer_Init(void);

/*
 * Enable buzzer
 */
void Buzzer_Enable(void);

/*
 * Disable buzzer
 */
void Buzzer_Disable(void);

/*
 * Set a frequency for the buzzer pwm
 */
void Buzzer_Frequency(uint8_t f);

#endif /* BUZZER_H_ */
