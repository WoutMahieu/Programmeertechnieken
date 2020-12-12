/*
 * OutputControl.h
 *
 *  Created on: 06 Nov 2020
 *      Author: WoutMahieu
 */

#ifndef OUTPUTCONTROL_H_
#define OUTPUTCONTROL_H_

#include "Lock.h"
#include "StatusLED.h"
#include "Buzzer.h"

/**
* Sets the statusLED, lockLED and buzzer to the locked state.
*/
void OutputControl_Lock(void);

/**
* Sets the statusLED, lockLED and buzzer to the unlocked state.
*/
void OutputControl_Unlock(void);

/**
* Sets the statusLED, lockLED and buzzer to the alarm state.
*/
void OutputControl_Alarm(void);

/**
* Sets the statusLED, lockLED and buzzer to the config state.
*/
void OutputControl_Config(void);

#endif /* OUTPUTCONTROL_H_ */
