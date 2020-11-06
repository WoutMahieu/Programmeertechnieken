/*
 * FSM.h
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef FSM_H_
#define FSM_H_

#include "ContactSwitch.h"
#include "RFID.h"
#include "DisplayControl.h"
#include "OutputControl.h"
#include "Delay.h"

extern enum states;
extern enum currentState;

void FSM_UpdateStates(void);
void FSM_Init(void);
void FSM_ExitInit(void);
void FSM_EnterLocked(void);
void FSM_Locked(void);
void FSM_ExitLocked(void);
void FSM_EnterOpened(void);
void FSM_Opened(void);
void FSM_ExitOpened(void);
void FSM_EnterForced(void);
void FSM_Forced(void);
void FSM_ExitForced(void);
void FSM_EnterConfig(void);
void FSM_Config(void);
void FSM_ExitConfig(void);

#endif /* FSM_H_ */
