/*
===============================================================================
 Name        : Programmeertechnieken.c
 Author      : Wout Mahieu & Lowie Lameire
 Description : Electric lock with RFID.
===============================================================================
*/
#include "FSM.h"

int main(void) {
	//continuously update the FSM
	while(1){
		FSM_UpdateStates();
	}

	return 0;
}
