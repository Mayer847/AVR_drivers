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





void init_LCD();
void LCD_voidCls();
void LCD_voidEN();
void LCD_voidRS(u8 STATE);
void LCD_voidCommand(u8 LCD_u8Winput);
void LCD_voidWriteData(u8 LCD_u8Winput);
void LCD_voidPrintStr(s8 *input);
void LCD_voidPrintNum(s16 int_input);


#endif /* LCD_INTERFACE_H_ */