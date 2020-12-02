/*
 * DisplayControl.h
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef DISPLAYCONTROL_H_
#define DISPLAYCONTROL_H_

#include "LCD.h"
#include "Joystick.h"
#include "InputControl.h"

void DisplayControl_InitScreen(void);
void DisplayControl_LockedScreen(void);
void DisplayControl_OpenedScreen(void);
void DisplayControl_AlarmScreen(void);
int Displaycontrol_ConfigScreen(void);
void DisplayControl_PrintTags(void);

void DisplayControl_PrintUpperLock(int x, int y);
void DisplayControl_PrintLowerLock(int x, int y);
void DisplayControl_PrintAlarm(int x, int y);

void DisplayControl_MenuBuilder();
void MenuPositionUpdater();
void MenuCursorUpdater();


#endif /* DISPLAYCONTROL_H_ */
