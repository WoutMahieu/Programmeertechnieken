/*
 * DisplayControl.c
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#include "DisplayControl.h"

//variables for the config menu
int position = 0;
int newPos = 0;
int tempPos = 0;

void DisplayControl_InitScreen(void){
	LCD_Clear();
	LCD_Cursor(0, 0);
	LCD_Print("Initializing");
	LCD_Update();
}

void DisplayControl_LockedScreen(void){
	LCD_Clear();
	DisplayControl_PrintLowerLock(3,12);
	DisplayControl_PrintUpperLock(4, 3);
	LCD_Cursor(23, 20);
	LCD_Print("Locked");
	LCD_Update();
}

void DisplayControl_OpenedScreen(void){
	LCD_Clear();
	DisplayControl_PrintLowerLock(3,12);
	DisplayControl_PrintUpperLock(17, 3);
	LCD_Cursor(23, 20);
	LCD_Print("Opened");
	LCD_Update();
}

void DisplayControl_AlarmScreen(void){
	LCD_Clear();
	DisplayControl_PrintAlarm(3,3);
	LCD_Cursor(23,20);
	LCD_Print("ALARM");
	LCD_Update();
}

void Displaycontrol_ConfigScreen(){
	LCD_Clear();
	Joystick_Enable();
	MenuStartUp();
	MenuBuilder();

	while(1){
		MenuPositionUpdater();

		if(position != tempPos){
			newPos = 1;
		}
		tempPos = position;

		if(newPos == 1){
			printf("%d\n", position);
			MenuCursorUpdater(position);
			newPos = 0;
		}
	}
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

void MenuStartUp(){
	LCD_Clear();
	LCD_Cursor(0, 0);
	LCD_Print("Configuration Menu");
	LCD_Update();
	while(InputControl_CheckJSCenter() == 0){}
	LCD_Clear();
}

void MenuBuilder(){
	LCD_Cursor(0, 0);
	LCD_Print("Add Tag");
	LCD_Cursor(0, 15);
	LCD_Print("Remove Tag");
	LCD_Cursor(63, 0);
	LCD_Print("Show Tags");
	LCD_Cursor(63, 15);
	LCD_Print("Option 4");
}

void MenuPositionUpdater(){
	int down = InputControl_CheckJSDown();
	int up = InputControl_CheckJSUp();
	int right = InputControl_CheckJSRight();
	int left = InputControl_CheckJSLeft();


	if(down){
		if(position < 4)
			position += 1;
		else
			position = 0;
	}

	else if(up){
		if(position > 0)
			position -= 1;
		else
			position = 3;
	}

	else if(right){
		if(position == 0)
			position = 2;
		else if(position == 1)
			position = 3;
		else if(position == 2)
			position = 0;
		else if(position == 3)
			position = 1;
	}

	else if(left){
		if(position == 0)
			position = 2;
		else if(position == 1)
			position = 3;
		else if(position == 2)
			position = 0;
		else if(position == 3)
			position = 1;
	}
}

void MenuCursorUpdater(int pos){

	Joystick_Disable();

	if(pos == 0){
		LCD_Rect(0, 9, 60, 10, 1);
		LCD_Rect(0, 24, 60, 25, 0);
		LCD_Rect(63, 9, 123, 10, 0);
		LCD_Rect(63, 24, 123, 25, 0);
		LCD_Update();
	}

	else if(pos == 1){
		LCD_Rect(0, 9, 60, 10, 0);
		LCD_Rect(0, 24, 60, 25, 1);
		LCD_Rect(63, 9, 123, 10, 0);
		LCD_Rect(63, 24, 123, 25, 0);
		LCD_Update();
	}

	else if(pos == 2){
		LCD_Rect(0, 9, 60, 10, 0);
		LCD_Rect(0, 24, 60, 25, 0);
		LCD_Rect(63, 9, 123, 10, 1);
		LCD_Rect(63, 24, 123, 25, 0);
		LCD_Update();
	}

	else if(pos == 3){
		LCD_Rect(0, 9, 60, 10, 0);
		LCD_Rect(0, 24, 60, 25, 0);
		LCD_Rect(63, 9, 123, 10, 0);
		LCD_Rect(63, 24, 123, 25, 1);
		LCD_Update();
	}

	Joystick_Enable();
}
