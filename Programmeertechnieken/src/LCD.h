/*
 * LCD.h
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef LCD_H_
#define LCD_H_

#include "lpc17xx.h"

extern uint32_t LCD_screenBuffer[128];
extern uint8_t LCD_autoUpdate;
extern uint8_t x, y;

void LCD_Init(void);
void LCD_Cmd(uint8_t cmd);
void LCD_Data(uint8_t data);
void LCD_SetPage(uint8_t page);
void LCD_SetColumn(uint8_t col);
void LCD_Clear(void);
void LCD_Update(void);
void LCD_Char(char c);
void LCD_Print(char *s);
void LCD_Cursor(uint8_t _x, uint8_t _y);
void LCD_Pixel(uint8_t x, uint8_t y, uint8_t c);
void LCD_Line(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t c);
void LCD_Square(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t c);

#endif /* LCD_H_ */
