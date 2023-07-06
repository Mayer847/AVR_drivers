/*
 * LCD_prog.c
 *
 * Created: 6/11/2023 10:36:44 AM
 *  Author: Mayer
 */ 
#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/Dio_interface.h"

#include "LCD_interface.h"
//#include <string.h>
//#include "../../../../Avr32/01_MCAL/01_DIO/Dio_interface.h"

void LCD_init(void){
	//set pin direction:(OUTPUT)
	Dio_voidSetPinDirection(LCD_PORT,D7_PIN,OUTPUT);
	Dio_voidSetPinDirection(LCD_PORT,D6_PIN,OUTPUT);
	Dio_voidSetPinDirection(LCD_PORT,D5_PIN,OUTPUT);
	Dio_voidSetPinDirection(LCD_PORT,D4_PIN,OUTPUT);
	Dio_voidSetPinDirection(EN_PORT,EN_PIN,OUTPUT);
	Dio_voidSetPinDirection(RS_PORT,RS_PIN,OUTPUT);
	_delay_ms(31);
	//0x02-return home -0x28-to define mode 4 bits -0x0c-display on cursor off,0x01-clear screan-
	LCD_voidCommand(0x33);
	_delay_ms(10);
	LCD_voidCommand(0x32);
	_delay_ms(10);
	LCD_voidCommand(0x28);
	LCD_voidCommand(0x0c);

}
void LCD_voidEN(){
	Dio_voidSetPinValue(EN_PORT,EN_PIN,HIGH);//PORT_A,PIN2
	_delay_ms(30);
	Dio_voidSetPinValue(EN_PORT,EN_PIN,LOW);
	_delay_ms(1);
}

void LCD_voidRS(u8 STATE){ //state is either COMMAND OR DATA
	Dio_voidSetPinValue(RS_PORT,RS_PIN,STATE);//low for command high for data
}

void LCD_voidCommand(u8 cmd){
	
	//RS=0
	LCD_voidRS(COMMAND);
	Dio_voidSetPinValue(EN_PORT,EN_PIN,LOW);
	//write values
	Dio_voidSetPinValue(LCD_PORT,D7_PIN,(cmd>>7)&1);
	Dio_voidSetPinValue(LCD_PORT,D6_PIN,(cmd>>6)&1);
	Dio_voidSetPinValue(LCD_PORT,D5_PIN,(cmd>>5)&1);
	Dio_voidSetPinValue(LCD_PORT,D4_PIN,(cmd>>4)&1);
		
	//Enable writing EN
	LCD_voidEN();
	
	Dio_voidSetPinValue(LCD_PORT,D7_PIN,(cmd>>3)&1);
	Dio_voidSetPinValue(LCD_PORT,D6_PIN,(cmd>>2)&1);
	Dio_voidSetPinValue(LCD_PORT,D5_PIN,(cmd>>1)&1);
	Dio_voidSetPinValue(LCD_PORT,D4_PIN,(cmd>>0)&1);
	//Enable writing EN
	LCD_voidEN();
}
void LCD_voidWriteData(u8 data){
	//RS=1
	LCD_voidRS(DATA);
	Dio_voidSetPinValue(EN_PORT,EN_PIN,LOW);
	//write values
	Dio_voidSetPinValue(LCD_PORT,D7_PIN,(data>>7)&1);
	Dio_voidSetPinValue(LCD_PORT,D6_PIN,(data>>6)&1);
	Dio_voidSetPinValue(LCD_PORT,D5_PIN,(data>>5)&1);
	Dio_voidSetPinValue(LCD_PORT,D4_PIN,(data>>4)&1);
	//Enable writing EN
	LCD_voidEN();
	
	Dio_voidSetPinValue(LCD_PORT,D7_PIN,(data>>3)&1);
	Dio_voidSetPinValue(LCD_PORT,D6_PIN,(data>>2)&1);
	Dio_voidSetPinValue(LCD_PORT,D5_PIN,(data>>1)&1);
	Dio_voidSetPinValue(LCD_PORT,D4_PIN,(data>>0)&1);
	//Enable writing EN
	LCD_voidEN();
	// Treat spaces as a special case
	/*if (data == ' ') {
		// Send a command to the LCD to properly handle spaces
		LCD_voidCommand(SPACE_COMMAND);
	}*/
}

void LCD_goto(u8 lcd_row, u8 lcd_pos) {
	u8 address=0;
	switch(lcd_row) {
		case 0:
		address = lcd_pos;
		break;
		case 1:
		address = lcd_pos + 0x40;
		break;
		case 2:
		address = lcd_pos + 0x14;
		break;
		case 3:
		address = lcd_pos + 0x54;
		break;
	}
	LCD_voidCommand(address | 0x80);
}


void LCD_voidPrintStr(char *input){
	for(u8 i=0;input[i]!='\0';i++){
		LCD_voidWriteData(input[i]);
	}
}

void LCD_voidPrintNum(s16 int_input){
	/*init_LCD();
	LCD_voidCls();*/
	s16 temp=int_input, i, j;
	char numStr[10] = "";
	for(i=0;temp>0;i++){
		numStr[i] = (temp%10) + '0';//strlen(numStr)
		//LCD_voidWriteData(temp%10 + '0');
		temp/=10;
		//LCD_voidWriteData(i+'0');
	}
	for(j=i-1;j>=0;j--){
		LCD_voidWriteData(numStr[j]);
	}
}


void LCD_voidCls(){
	LCD_voidCommand(0x01);
}
void LCD_setCursor(u8 col, u8 row) {
	u8 address = (row == 0 ? 0x80 : 0xC0) + col;
	//PORTD_REG = (PORTD_REG & 0x0F) | ((address >> 4) << 4);
	PORTB_REG = (PORTB_REG & 0xF0) | (address & 0x0F);
	_delay_us(50);
}
void LCD_create_char(u8 location, u8 *charmap)
{
	u8 i;
	location &= 0x07; // we only have 8 locations 0-7
	LCD_voidCommand(0x40 + (location * 8)); // set CGRAM address
	for (i = 0; i < 8; i++)
		LCD_voidWriteData(charmap[i]);
}
/*4 bit initialization
	LCD_voidCommand(0x20);//0b0010 
	//LCD_voidCommand(0x20);//0b0010
	LCD_voidCommand(0X20);
	//LCD_voidCommand(0x00);//N=0:1 -Line display F=0:5x7 dot character font
	LCD_voidCommand(0X0f);//cursor
	LCD_voidCommand(0x06);
	//LCD_voidCommand(0x00);
	LCD_voidCommand(0x80);
	
	LCD_voidCommand(0x00);
	LCD_voidCommand(0x10);
	
	LCD_voidCommand(0x00);
	LCD_voidCommand(0x60);*/
	/*4bit initialization 2nd attempt
	LCD_voidCommand(0x2);
	LCD_voidCommand(0x2);
	LCD_voidCommand(0x0);
	LCD_voidCommand(0x1);
	LCD_voidCommand(0x0);
	LCD_voidCommand(0x4);*/
	/*4bit init attempt 3:LCD_voidCommand(0x02);
	LCD_voidCommand(0x28);
	LCD_voidCommand(0x0c);
	LCD_voidCommand(0x06);
	LCD_voidCommand(0x01);*/
	/*8bit initialization
	LCD_voidCommand(0x30);
	LCD_voidCommand(0x08);
	LCD_voidCommand(0x01);
	LCD_voidCommand(0x04);*/