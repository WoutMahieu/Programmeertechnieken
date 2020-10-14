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
	LCD_Print("HeLLo WOrlD");
	LCD_Cursor(5,6);
	LCD_Print("GLITCHING... I GUESS");

	return 0;
}
