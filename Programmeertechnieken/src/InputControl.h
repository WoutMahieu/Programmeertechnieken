/*
 * InputControl.h
 *
 *  Created on: 8 nov. 2020
 *      Author: Lowie Lameire
 */

#ifndef INPUTCONTROL_H_
#define INPUTCONTROL_H_

#include "Joystick.h"
#include "ContactSwitch.h"
#include "RFID.h"

/*
 * Check for joystick center input
 * @return '1' if input, '0' if no input
 */
int InputControl_CheckJSCenter(void);

/*
 * Check for joystick down input
 * @return '1' if input, '0' if no input
 */
int InputControl_CheckJSDown(void);

/*
 * Check for joystick left input
 * @return '1' if input, '0' if no input
 */
int InputControl_CheckJSLeft(void);

/*
 * Check for joystick right input
 * @return '1' if input, '0' if no input
 */
int InputControl_CheckJSRight(void);

/*
 * Check for joystick up input
 * @return '1' if input, '0' if no input
 */
int InputControl_CheckJSUp(void);

/*
 * Check if the contact switch is closed
 * @return '1' if closed, '0' if open
 */
int InputControl_CheckCS(void);

/*
 * Set the RFID mode
 * @param m = mode to set to
 */
void InputControl_ModeRFID(int m);

/*
 * Check if the scanned RFID tag is valid
 * @return '1' if valid, '0' if invalid
 */
int InputControl_CheckRFID(void);

/*
 * Check how many invalid tags have been scanned in a row
 * @return the amount of invalid tries
 */
int InputControl_CheckRFIDFalseTries(void);

/*
 * Set the amount of invalid tries in a row
 * @param v = amount of invalid tries in a row
 */
void InputControl_SetRFIDFalseTries(int v);

/*
 * Enable the joystick interrupts
 */
void InputControl_EnableJoystick(void);

/*
 * disable the joystick interrupts
 */
void InputControl_DisableJoystick(void);

#endif /* INPUTCONTROL_H_ */
