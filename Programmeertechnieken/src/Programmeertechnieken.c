/*
===============================================================================
 Name        : Programmeertechnieken.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/
#include "FSM.h"
#include "LCD.h"

int main(void) {

	while(1){
		FSM_UpdateStates();
	}

	return 0;
}
