/*
 * LCD_interface.h
 *
 * Created: 6/11/2023 10:36:11 AM
 *  Author: Mayer
 */ 


#ifndef LCD_INTERFACE_H_
#define LCD_INTERFACE_H_

#include "LCD_config.h"
#include "LCD_private.h"

#define COMMAND	LOW
#define DATA	HIGH

/*#define SPACE_COMMAND 0b00100000*/



void LCD_init();
void LCD_voidCls();
void LCD_voidEN();
void LCD_voidRS(u8 STATE);
void LCD_voidCommand(u8 LCD_u8Winput);
void LCD_voidWriteData(u8 LCD_u8Winput);
void LCD_voidPrintStr(char *input);
void LCD_voidPrintNum(s16 int_input);
void LCD_create_char(u8 location, u8 *charmap);
void LCD_goto(u8 LCD_row, u8 pixel_pos);
void LCD_setCursor(u8 col, u8 row);

#endif /* LCD_INTERFACE_H_ */