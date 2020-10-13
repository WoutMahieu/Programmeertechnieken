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
	return 0;
}
