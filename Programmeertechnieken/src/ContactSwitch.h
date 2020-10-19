/*
 * ContactSwitch.h
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef CONTACTSWITCH_H_
#define CONTACTSWITCH_H_

#include "lpc17xx.h"

void ContactSwitch_Init(void);
uint8_t ContactSwitch_GetFlag(void);

#endif /* CONTACTSWITCH_H_ */
