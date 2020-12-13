/*
 * LCD.h
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#ifndef LCD_H_
#define LCD_H_

#include "SSP.h"
#include "Delay.h"
#include "lpc17xx.h"

extern uint32_t LCD_screenBuffer[128];
extern uint8_t LCD_autoUpdate;
extern uint8_t x, y;

/*
 * Initialize the LCD & SSP
 */
void LCD_Init(void);

/*
 * Send a commant to the LCD
 * @param cmd = command to send
 */
void LCD_Cmd(uint8_t cmd);

/*
 * Send data to the LCD
 * @param data = data to send
 */
void LCD_Data(uint8_t data);

/*
 * Set the page of the LCD
 * @param page = page to set
 */
void LCD_SetPage(uint8_t page);

/*
 * Set the column of the LCD
 * @param col = column to set
 */
void LCD_SetColumn(uint8_t col);

/*
 * Clear the LCD
 */
void LCD_Clear(void);

/*
 * Update the LCD
 */
void LCD_Update(void);

/*
 * Place a char at the cursors position
 * @param c = char to set
 */
void LCD_Char(char c);

/*
 * Print a string at the cursors position
 * @param *s = ptr to first char of the string
 */
void LCD_Print(char *s);

/*
 * Move the cursor on the LCD
 * @param x = x position
 * @param y = y position
 */
void LCD_Cursor(uint8_t _x, uint8_t _y);

/*
 * Set a pixel on the LCD
 * @param x = x position
 * @param y = y position
 * @param c = color
 */
void LCD_Pixel(uint8_t x, uint8_t y, uint8_t c);

/*
 * Set a rectangle on the LCD
 * @param x1 = x position upper left corner
 * @param y1 = y position upper left corner
 * @param x2 = x position lower right corner
 * @param y2 = y position lower right corner
 * @param c = color
 */
void LCD_Rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t c);

#endif /* LCD_H_ */
