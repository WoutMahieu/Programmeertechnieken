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

/*
* Sets the statusLED to blue, lockLED to on and buzzer to off
*/
void OutputControl_Lock(void);

/*
* Sets the statusLEDto green, lockLED to off and buzzer to off
*/
void OutputControl_Unlock(void);

/*
* Sets the statusLED to red and buzzer to on
*/
void OutputControl_Alarm(void);

/*
* Sets the statusLED to yellow and buzzer to off
*/
void OutputControl_Config(void);

#endif /* OUTPUTCONTROL_H_ */
