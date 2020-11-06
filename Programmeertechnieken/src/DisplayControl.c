/*
 * DisplayControl.c
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#include "DisplayControl.h"

void DisplayControl_InitScreen(void){
	LCD_Cursor(0, 0);
	LCD_Print("Initializing");
	LCD_Update();
}

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
	DisplayControl_PrintAlarm(3,3);
	LCD_Cursor(23,20);
	LCD_Print("ALARM");
	LCD_Update();
}

void Displaycontrol_ConfigScreen(int pos){

}

void DisplayControl_PrintUpperLock(int x, int y){
	LCD_Rect(x, y + 5, x + 2, y + 5 + 6, 1);
	LCD_Rect(x + 1, y + 3, x + 1 + 2, y + 3 + 2, 1);
	LCD_Rect(x + 2, y + 2, x + 2 + 2, y + 2 + 2, 1);
	LCD_Rect(x + 3, y + 1, x + 3 + 2, y + 1 + 2, 1);
	LCD_Rect(x + 5, y, x + 5 + 5, y + 2, 1);
	LCD_Rect(x + 10, y + 1, x + 10 + 2, y + 1 + 2, 1);
	LCD_Rect(x + 11, y + 2, x + 11 + 2, y + 2 + 2, 1);
	LCD_Rect(x + 12, y + 3, x + 12 + 2, y + 3 + 2, 1);
	LCD_Rect(x + 13, y + 5, x + 13 + 2, y + 5 + 6, 1);
	LCD_Pixel(x + 14, y + 11, 1);
}

void DisplayControl_PrintLowerLock(int x, int y){
	LCD_Rect(x, y, x + 17, y + 17, 1);
	LCD_Rect(x + 7, y + 5, x + 7 + 3, y + 5 + 3, 0);
	LCD_Rect(x + 8, y + 8, x + 9, y + 8 + 4, 0);
}

void DisplayControl_PrintAlarm(int x, int y){
	LCD_Rect(x, y + 22, x + 17, y + 22 + 3, 1);
	LCD_Rect(x + 1, y + 12, x + 1 + 1, y + 12 + 10, 1);
	LCD_Rect(x + 2, y + 10, x + 2 + 1, y + 10 + 3, 1);
	LCD_Rect(x + 3, y + 9, x + 3 + 1, y + 9 + 2, 1);
	LCD_Rect(x + 4, y + 8, x + 4 + 1, y + 8 + 2, 1);
	LCD_Rect(x + 5, y + 8, x + 5 + 7, y + 8 + 1, 1);
	LCD_Rect(x + 12, y + 8, x + 12 + 1, y + 8 + 2, 1);
	LCD_Rect(x + 13, y + 9, x + 13 + 1, y + 9 + 2, 1);
	LCD_Rect(x + 14, y + 10, x + 14 + 1, y + 10 + 3, 1);
	LCD_Rect(x + 15, y + 12, x + 15 + 1, y + 12 + 10, 1);

	LCD_Rect(x + 6, y + 10, x + 6 + 2, y + 10 + 1, 1);
	LCD_Pixel(x + 5, y + 11, 1);
	LCD_Pixel(x + 4, y + 12, 1);
	LCD_Rect(x + 3, y + 13, x + 3 + 1, y + 13 + 5, 1);

	LCD_Pixel(x, y + 2, 1);
	LCD_Pixel(x + 1, y + 3, 1);
	LCD_Pixel(x + 2, y + 4, 1);
	LCD_Pixel(x + 8, y, 1);
	LCD_Pixel(x + 8, y + 1, 1);
	LCD_Pixel(x + 8, y + 2, 1);
	LCD_Pixel(x + 8, y + 3, 1);
	LCD_Pixel(x + 8, y + 4, 1);
	LCD_Pixel(x + 15, y + 4, 1);
	LCD_Pixel(x + 16, y + 3, 1);
	LCD_Pixel(x + 17, y + 2, 1);
}
