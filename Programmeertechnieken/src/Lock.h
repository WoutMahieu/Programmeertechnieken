/*
 * Lock.h
 *
 *  Created on: 24 okt. 2020
 *      Author: Lowie Lameire
 */

#ifndef LOCK_H_
#define LOCK_H_

#include "LPC17xx.h"

void Lock_Init();

void Lock_DriveLock(int bool);

#endif /* LOCK_H_ */
