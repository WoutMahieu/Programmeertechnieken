/*
 * LCD.h
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef LCD_H_
#define LCD_H_

#include "lpc17xx.h"

void LCD_Init(void);
void LCD_Cmd(uint8_t cmd);
void LCD_Data(uint8_t data);

#endif /* LCD_H_ */
