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

/*
 * Initialize SSP
 */
void SSP_Init(void);

/*
 * Write SPI data
 * @param data = data to write
 * @return = data returned by the slave
 */
uint8_t SSP_Write(uint8_t data);

#endif /* SSP_H_ */
