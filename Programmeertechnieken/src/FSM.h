/*
 * FSM.h
 * Created on: 19 Oct 2020
 * Author: Wout Mahieu
 */

#ifndef FSM_H_
#define FSM_H_

#include "DisplayControl.h"
#include "OutputControl.h"
#include "InputControl.h"
#include "HardwareInit.h"
#include "Timer.h"

/*
 * Updates the state machine, depending on the current state
 */
void FSM_UpdateStates(void);

/*
 * Method called to init the program, initializes all the hardware
 */
void FSM_Init(void);

/*
 * Called when exiting the Init state, empty function
 */
void FSM_ExitInit(void);

/*
 * Called when entering the locked state: displays the locked screen,
 * changes the status LED to blue & closes the lock
 */
void FSM_EnterLocked(void);

/*
 * Locked state, empty function
 */
void FSM_Locked(void);

/*
 * Called when exiting the locked state: reset the invalid tries of the RFID tags
 */
void FSM_ExitLocked(void);

/*
 * Called when entering the opened state: displays the opened screen, opens the lock,
 * changes status LED to green & enables the joystick
 */
void FSM_EnterOpened(void);

/*
 * Opened state, empty function
 */
void FSM_Opened(void);

/*
 * Called when exiting the opened state: disables the joystick, resets the invalid tries of the RFID tags
 * and stops the closed timer
 */
void FSM_ExitOpened(void);

/*
 * Called when entering the forced state: displays the alarm sceen
 * and enables the alarm (buzzer on & status LED to red)
 */
void FSM_EnterForced(void);

/*
 * Forced state, empty function
 */
void FSM_Forced(void);

/*
 * Called when exiting the forced state: resets the invalid tries of the RFID tags
 */
void FSM_ExitForced(void);

/*
 * Called when entering the config state: enables the joystick, shows the config screen
 * and changes the status LED to yellow
 */
void FSM_EnterConfig(void);

/*
 * Config state, sets the correct RFID mode depending on the joystick input
 */
void FSM_Config(void);

/*
 * Called when exiting the config state: disables joystick and set the RFID mode to lock/unlock
 */
void FSM_ExitConfig(void);

#endif /* FSM_H_ */
