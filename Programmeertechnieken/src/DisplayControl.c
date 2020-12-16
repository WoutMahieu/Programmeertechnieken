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
int tempPos = 1;

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
	LCD_Cursor(63, 10);
	LCD_Print("Press CENTER");
	LCD_Cursor(63, 20);
	LCD_Print("for config");
	LCD_Update();
}

void DisplayControl_AlarmScreen(void){
	LCD_Clear();
	DisplayControl_PrintAlarm(3,3);
	LCD_Cursor(23,20);
	LCD_Print("ALARM");
	LCD_Update();
}

void DisplayControl_PrintTags(){
	LinkedList_t* walkingPtr = RFID_GetLL();
	while(walkingPtr != NULL){
		LCD_Clear();
		LCD_Cursor(0,0);
		LCD_Print(walkingPtr->value);
		LCD_Update();
		Wait_s(2);
		walkingPtr = walkingPtr->nextPtr;
	}
	DisplayControl_MenuBuilder();
}

int Displaycontrol_ConfigScreen(){
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

	return position;
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

void DisplayControl_MenuBuilder(){
	LCD_Clear();

	newPos = position = 0;
	tempPos = 1;

	LCD_Cursor(0, 0);
	LCD_Print("Add tag");
	LCD_Cursor(63, 0);
	LCD_Print("Remove tag");
	LCD_Cursor(0, 12);
	LCD_Print("Print tags");
	LCD_Cursor(0, 24);
	LCD_Print("Press CENTER to return");
	LCD_Update();
}

void MenuPositionUpdater(){
	int right = InputControl_CheckJSRight();
	int left = InputControl_CheckJSLeft();
	int up = InputControl_CheckJSUp();
	int down = InputControl_CheckJSDown();

	if(right || left){
		if(position == 0)
			position = 1;
		else if(position == 1)
			position = 0;
	}

	if(up || down){
		if(position == 0 || position == 1)
			position = 2;
		else if(position == 2)
			position = 0;
	}
}

void MenuCursorUpdater(int pos){

	InputControl_DisableJoystick();

	if(pos == 0){
		LCD_Rect(0, 9, 60, 10, 1);
		LCD_Rect(0, 21, 60, 22, 0);
		LCD_Rect(63, 9, 123, 10, 0);
		LCD_Update();
	}

	else if(pos == 1){
		LCD_Rect(0, 9, 60, 10, 0);
		LCD_Rect(0, 21, 60, 22, 0);
		LCD_Rect(63, 9, 123, 10, 1);
		LCD_Update();
	}

	else if(pos == 2){
		LCD_Rect(0, 9, 60, 10, 0);
		LCD_Rect(0, 21, 60, 22, 1);
		LCD_Rect(63, 9, 123, 10, 0);
		LCD_Update();
	}

	InputControl_EnableJoystick();
}
