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
#include "Joystick.h"

// TODO: insert other definitions and declarations here

int main(void) {
<<<<<<< HEAD
	LCD_Init();
	LCD_Cursor(10, 15);
	LCD_Write("a");
	LCD_Cursor(15, 10);
	LCD_Write("b");
	LCD_Cursor(80, 3);
	LCD_Write("c");
=======
	JS_init();
	JS_enable();

	while(1){
		if(getJSFlags() == 1){
			printf("LEFT\n");
			setJSFlags(0);
		}
		else if(getJSFlags() == 2){
			printf("CENTER\n");
			setJSFlags(0);
		}
		else if(getJSFlags() == 4){
			printf("DOWN\n");
			setJSFlags(0);
		}
		else if(getJSFlags() == 8){
			printf("UP\n");
			setJSFlags(0);
		}
		else if(getJSFlags() == 16){
			printf("RIGHT\n");
			setJSFlags(0);
		}
	}
>>>>>>> branch 'master' of https://github.com/WoutMahieu/Programmeertechnieken
	return 0;
}
