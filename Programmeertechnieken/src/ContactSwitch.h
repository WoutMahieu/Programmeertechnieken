/*
 * ContactSwitch.h
 *
 *  Created on: 19 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef CONTACTSWITCH_H_
#define CONTACTSWITCH_H_

#include "lpc17xx.h"

/*
 * Initialize the contact switch
 */
void ContactSwitch_Init(void);

/*
 * Get the contact switch status
 * @return '1' if closed, '0' if open
 */
uint8_t ContactSwitch_GetFlag(void);

#endif /* CONTACTSWITCH_H_ */
