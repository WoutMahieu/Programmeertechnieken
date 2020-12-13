/*
 * LCD.c
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#include "LCD.h"
#include "Fonts.h"

uint32_t LCD_screenBuffer[128] = { };
uint8_t LCD_autoUpdate = 1;
uint8_t x, y = 0;

void LCD_Init(void){
	//initialize SSP
	SSP_Init();

	//Reset the LCD
	LPC_GPIO0->FIOCLR |= (1 << 8);
	Wait_us(50);
	LPC_GPIO0->FIOSET |= (1 << 8);
	Wait_ms(5);

	LCD_Cmd(0xAE); //display off

	LCD_Cmd(0xA2); //bias voltage
	LCD_Cmd(0xA0); //set display RAM address SEG output correspondence to normal
	LCD_Cmd(0xC8); //set column normal
	LCD_Cmd(0x22); //select internal resistor ratio
	LCD_Cmd(0x2F); //select internal power supply mode (power on)
	LCD_Cmd(0x40); //select first line as start address

	LCD_Cmd(0xAF); //display on

	LCD_Cmd(0x81); //set the output voltage register (contrast)
	LCD_Cmd(0x17); //contrast value
	LCD_Cmd(0xA6); //display normal
	LCD_Cmd(0xE0); //read-modify-write

	LCD_Clear();
}

void LCD_Cmd(uint8_t data){
	LPC_GPIO0->FIOCLR |= (1 << 6); //A0 = 0 => command
	SSP_Write(data);
	LPC_GPIO0->FIOSET |= (1 << 6); //A0 = 1 => data
}

void LCD_Data(uint8_t data){
	LPC_GPIO0->FIOSET |= (1 << 6); //A0 = 1 => data
	SSP_Write(data);
	LPC_GPIO0->FIOCLR |= (1 << 6); //A0 = 0 => command
}

void LCD_SetPage(uint8_t page){
	LCD_Cmd((0xB0 | page));
}

void LCD_SetColumn(uint8_t col){
	LCD_Cmd((0x0F & col));
	LCD_Cmd(0x10 | ((0xF0 & col) >> 4));
}


void LCD_Clear(void){
	for(uint8_t i = 0; i < 128; i++){
		LCD_screenBuffer[i] = 0x00000000;
	}

	LCD_Update();
	LCD_Cursor(0,0);
}

void LCD_Update(void){
	for(uint8_t p = 0; p < 4; p++){
		LCD_SetPage(p);
		LCD_SetColumn(0);

		for(uint8_t i = 0; i < 128; i++){
			uint8_t d = ((LCD_screenBuffer[i] & (0xFF << (8*p))) >> (8*p));
			LCD_Data(d);
		}
	}
}

void LCD_Char(char c){
	uint16_t i, j;
	i = (c - ' ') * 5;

	for(j = 0; j < Fonts_normal[i]; j++){
		LCD_screenBuffer[x] &= ~(0xFF << y);
		LCD_screenBuffer[x] |= (Fonts_normal[1 + i + j] << y);
		x++;
	}

	//1px whitespace after any char
	LCD_screenBuffer[x] &= ~(0xFF << y);
	x++;
}

void LCD_Print(char *s){
	while(*s){
		LCD_Char(*s);
		s++;
	}

	if(LCD_autoUpdate){
		LCD_Update();
	}
}

void LCD_Cursor(uint8_t _x, uint8_t _y){
	x = _x;
	y = _y;
}

void LCD_Pixel(uint8_t x, uint8_t y, uint8_t c){
	if(c == 1){
		LCD_screenBuffer[x] |= (0x01 << y);
	}
	else{
		LCD_screenBuffer[x] &= ~(0x01 << y);
	}


	if(LCD_autoUpdate){
		LCD_Update();
	}
}

void LCD_Rect(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t c){
	for(uint8_t x = x1; x < x2; x++){
		for(uint8_t y = y1; y < y2; y++){
			LCD_Pixel(x, y, c);
		}
	}

	if(LCD_autoUpdate){
		LCD_Update();
	}
}
