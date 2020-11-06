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

void OutputControl_Lock(void);
void OutputControl_Unlock(void);
void OutputControl_Alarm(void);

#endif /* OUTPUTCONTROL_H_ */
