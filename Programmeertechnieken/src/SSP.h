/*
 * SSP.h
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef SSP_H_
#define SSP_H_

#include "lpc17xx.h"
#include "Delay.h"

void SSP_Init(void);
uint8_t SSP_Write(uint8_t data);

#endif /* SSP_H_ */