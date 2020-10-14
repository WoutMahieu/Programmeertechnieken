/*
===============================================================================
 Name        : Programmeertechnieken.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#ifdef __USE_CMSIS
#include "LPC17xx.h"
#endif

#include <cr_section_macros.h>

#include <stdio.h>

// TODO: insert other include files here
#include "LCD.h"

// TODO: insert other definitions and declarations here

int main(void) {
	LCD_Init();
	LCD_Cursor(10, 15);
	LCD_Write("a");
	LCD_Cursor(15, 10);
	LCD_Write("b");
	LCD_Cursor(80, 3);
	LCD_Write("c");
	return 0;
}
