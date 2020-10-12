/*
 * LCD.h
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef LCD_H_
#define LCD_H_

#include "lpc17xx.h"

extern uint8_t LCD_screenBuffer[512];

void LCD_Init(void);
void LCD_Cmd(uint8_t cmd);
void LCD_Data(uint8_t data);
void LCD_SetPage(uint8_t page);
void LCD_SetColumn(uint8_t col);
void LCD_Clear(void);
void LCD_Update(void);

#endif /* LCD_H_ */
