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

/*
 * Initialize the LEDs
 */
void StatusLED_Init(void);

/*
 * Set the red LED
 * @param bool = on/off
 */
void StatusLED_Red(int bool);

/*
 * Set the red LED
 * @param bool = on/off
 */
void StatusLED_Green(int bool);

/*
 * Set the red LED
 * @param bool = on/off
 */
void StatusLED_Blue(int bool);

/*
 * FLash the LEDs that are on
 */
void StatusLED_Flash(void);

#endif /* STATUSLED_H_ */
