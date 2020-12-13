/*
 * DisplayControl.h
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef DISPLAYCONTROL_H_
#define DISPLAYCONTROL_H_

#include "LCD.h"
#include "InputControl.h"

/*
 * Display the initialization screen
 */
void DisplayControl_InitScreen(void);

/*
 * Display the locked screen
 */
void DisplayControl_LockedScreen(void);

/*
 * Display the opened screen
 */
void DisplayControl_OpenedScreen(void);

/*
 * Display the alarm screen
 */
void DisplayControl_AlarmScreen(void);

/*
 * Display the config screen
 * @return the current position of the line under the possible functions
 */
int Displaycontrol_ConfigScreen(void);

/*
 * Print the current valid tags, one by one
 */
void DisplayControl_PrintTags(void);

/*
 * print the upper lock to the screen
 * @param x = x position
 * @param y = y position
 */
void DisplayControl_PrintUpperLock(int x, int y);

/*
 * print the lower lock to the screen
 * @param x = x position
 * @param y = y position
 */
void DisplayControl_PrintLowerLock(int x, int y);

/*
 * print the alarm to the screen
 * @param x = x position
 * @param y = y position
 */
void DisplayControl_PrintAlarm(int x, int y);

/*
 * Build the config menu on the screen
 */
void DisplayControl_MenuBuilder(void);

/*
 * Update the indicator line position, depending on the joystick input
 */
void MenuPositionUpdater(void);

/*
 * Print the indicator line at the new position, disable the joystick while printing
 * @param pos = position to print the line
 */
void MenuCursorUpdater(int pos);


#endif /* DISPLAYCONTROL_H_ */
