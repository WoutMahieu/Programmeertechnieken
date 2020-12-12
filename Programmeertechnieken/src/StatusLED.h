/*
 * StatusLED.h
 *
 *  Created on: 06 Nov 2020
 *      Author: WoutMahieu
 */

#ifndef STATUSLED_H_
#define STATUSLED_H_

#include "LPC17xx.h"
#include "Delay.h"

void StatusLED_Init(void);
void StatusLED_Red(int bool);
void StatusLED_Green(int bool);
void StatusLED_Blue(int bool);
void StatusLED_Flash();

#endif /* STATUSLED_H_ */
