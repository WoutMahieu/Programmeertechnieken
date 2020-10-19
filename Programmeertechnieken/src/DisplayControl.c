/*
 * DisplayControl.c
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#include "DisplayControl.h"

void DisplayControl_LockedScreen(void){
	DisplayControl_PrintLowerLock(3,12);
	DisplayControl_PrintUpperLock(4, 3);
	LCD_Cursor(23, 20);
	LCD_Print("Locked");
	LCD_Update();
}

void DisplayControl_OpenedScreen(void){
	DisplayControl_PrintLowerLock(3,12);
	DisplayControl_PrintUpperLock(17, 3);
	LCD_Cursor(23, 20);
	LCD_Print("Opened");
	LCD_Update();
}

void DisplayControl_AlarmScreen(void){

}

void Displaycontrol_ConfigScreen(void){

}

void DisplayControl_PrintUpperLock(int x, int y){
	LCD_Square(x, y + 5, x + 2, y + 5 + 6, 1);
	LCD_Square(x + 1, y + 3, x + 1 + 2, y + 3 + 2, 1);
	LCD_Square(x + 2, y + 2, x + 2 + 2, y + 2 + 2, 1);
	LCD_Square(x + 3, y + 1, x + 3 + 2, y + 1 + 2, 1);
	LCD_Square(x + 5, y, x + 5 + 5, y + 2, 1);
	LCD_Square(x + 10, y + 1, x + 10 + 2, y + 1 + 2, 1);
	LCD_Square(x + 11, y + 2, x + 11 + 2, y + 2 + 2, 1);
	LCD_Square(x + 12, y + 3, x + 12 + 2, y + 3 + 2, 1);
	LCD_Square(x + 13, y + 5, x + 13 + 2, y + 5 + 6, 1);
	LCD_Pixel(x + 14, y + 11, 1);
}

void DisplayControl_PrintLowerLock(int x, int y){
	LCD_Square(x, y, x + 17, y + 17, 1);
	LCD_Square(x + 7, y + 5, x + 7 + 3, y + 5 + 3, 0);
	LCD_Square(x + 8, y + 8, x + 9, y + 8 + 4, 0);
}

void DisplayControl_PrintAlarm(int x, int y){

}
