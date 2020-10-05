/*
 * LCD.c
 *
 *  Created on: 05 Oct 2020
 *      Author: WoutMahieu
 */

#include "LCD.h"
#include "lpc17xx.h"
#include "SSP.h"
#include "Delay.h"

void LCD_Init(){
	//initialize SSP
	SSP_Init();

	//Reset the LCD
	LPC_GPIO0->FIOCLR |= (1 << 8);
	Wait_us(50);
	LPC_GPIO0->FIOSET |= (1 << 8);

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
}

void LCD_Cmd(uint8_t data){
	LPC_GPIO0->FIOCLR |= (1 << 6); //A0 = 0 => command
	SSP_Write(data);
	LPC_GPIO0->FIOSET |= (1 << 6); //A0 = 0 => data
}

void LCD_Data(uint8_t data){
	LPC_GPIO0->FIOSET |= (1 << 6);
}


