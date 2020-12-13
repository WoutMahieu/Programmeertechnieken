/*
 * HardwareInit.h
 *
 *  Created on: 8 nov. 2020
 *      Author: Lowie Lameire
 */

#ifndef HARDWAREINIT_H_
#define HARDWAREINIT_H_

#include "Buzzer.h"
#include "ContactSwitch.h"
#include "DisplayControl.h"
#include "Joystick.h"
#include "LCD.h"
#include "Lock.h"
#include "RFID.h"
#include "StatusLED.h"

/*
* Calls all hardware initialization functions
*/
void HardwareInit(void);

#endif /* HARDWAREINIT_H_ */
