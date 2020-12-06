/*
 * Lock.h
 *
 *  Created on: 24 okt. 2020
 *      Author: Lowie Lameire
 */

#ifndef LOCK_H_
#define LOCK_H_

#include "LPC17xx.h"

/**
* Initialize hardware for the visualization of the lock (LED)
*/
void Lock_Init();

/**
* Open or closes the lock
*
* @param bool  0 to close the lock, 1 to open the lock
*/
void Lock_DriveLock(int bool);

/**
* Open or closes the lock
*
* @return  0 if lock is closed, 1 if lock is opened
*/
int Lock_GetStatus();

#endif /* LOCK_H_ */
