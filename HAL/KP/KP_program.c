#define F_CPU 16000000UL
#include <util/delay.h>

#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/Dio_interface.h"
#include "../../MCAL/DIO/Dio_private.h"
#include "../LCD/LCD_interface.h"
#include "../SW/SW_interface.h"

#include "KP_interface.h"

void KP_init(){
	// dir of pins dir of output and input high, define pins, pull up resistor in input
	//define COL direction
	Dio_voidSetPinDirection(COL,C1,INPUT);
	Dio_voidSetPinDirection(COL,C2,INPUT);
	Dio_voidSetPinDirection(COL,C3,INPUT);
	Dio_voidSetPinDirection(COL,C4,INPUT);
	//define ROW direction
	Dio_voidSetPinDirection(ROW,R1,OUTPUT);
	Dio_voidSetPinDirection(ROW,R2,OUTPUT);
	Dio_voidSetPinDirection(ROW,R3,OUTPUT);
	Dio_voidSetPinDirection(ROW,R4,OUTPUT);
	//set ROW OUTPUT AS HIGH
	Dio_voidSetPinValue(COL,C1,HIGH);
	Dio_voidSetPinValue(COL,C2,HIGH);
	Dio_voidSetPinValue(COL,C3,HIGH);
	Dio_voidSetPinValue(COL,C4,HIGH);
}

void KP_password(){
	u8 flag = 0;//password is incorrect if 0
	for(int j=0;j<3 && !flag;j++){
		LCD_voidCls();
		LCD_voidPrintStr("Enter Password:");
		u8 passArr[4]=PASS;
		u8 passw[4];
		for(u8 i=0;i<4;i++){
			while(KP_getChar()==NOT_PRESSED);
			passw[i]=KP_getChar();
			//LCD_voidCommand(0xc0);
			_delay_ms(250);
			LCD_voidWriteData('*');
		}
		LCD_voidCls();
		//u8 flag2=0;//0 is incorrect
		u8 k;
		for(k=0;k<4;k++){
			if(passw[k]!=passArr[k]){
				break;
			}
		}
		if(k==4){
			flag=1;
			break;
		}
	}
	if(flag){
		LCD_voidPrintStr("Welcome to Paradise!");
		_delay_ms(400);
	}
	else{
		//ring buzzer
		Dio_voidSetPinDirection(BUZZ_PORT,BUZZ_PIN,OUTPUT);
		Dio_voidSetPinValue(BUZZ_PORT,BUZZ_PIN,HIGH);
		_delay_ms(500);
		Dio_voidSetPinValue(BUZZ_PORT,BUZZ_PIN,LOW);
		LCD_voidPrintStr("Welcome to HELL!!!");
		_delay_ms(400);
	}
}

u8 KP_getChar(){
	u8 ROW_ARR[4]= {R1,R2,R3,R4};
	u8 COL_ARR[4]= {C1,C2,C3,C4};
	u8 ARR[4][4]=KP_ARR;
	u8 kypad_val=NOT_PRESSED;
	for(int r=0;r<4;r++)
	{
		
		//SET_PINVALUE ROW = LOW
		Dio_voidSetPinValue(ROW,ROW_ARR[r],LOW);
		for(int c=0;c<4;c++)
		{
			if(Dio_u8GetPinValue(COL,COL_ARR[c])==LOW){
				_delay_ms(20);//for debouncing click
				kypad_val= ARR[r][c];
			}
		}
		//SET PIN VALUE ROW = HIGH
		Dio_voidSetPinValue(ROW,ROW_ARR[r],HIGH);
	}
	
	return kypad_val;
}

u8 KP_u8SimpleCalc(){
	LCD_voidCls();
	//variable init.:
	s16 result=0,input1=0,input2=0;
	u8 op=0xff,i=0,temp;
	//getting 1st input:
	while(i<3){ //get 3 digit input or user inputs a non-number character
		while(KP_getChar()==NOT_PRESSED);
		temp=KP_getChar();
		_delay_ms(220);
		/*if(temp==TGL){
			return SW_resCalc();
		}*/
		if(temp>='0'&& temp<='9')//if input is a number then use and display it
		{
			input1=input1*10 + (temp-'0');
			LCD_voidWriteData(temp);
			i++;
		}
		else if(temp=='+'||temp=='-'||temp=='/'||temp=='*'){
			op=temp;
			LCD_voidWriteData(op);
			break;
		}
	}
	//LCD_voidPrintStr("(1)");
	//get operator
	while(op==0xff){
		while(KP_getChar()==NOT_PRESSED);
		temp= KP_getChar();
		_delay_ms(220);
		/*if(temp==TGL){
			return SW_resCalc();
		}*/
		if(temp=='+'||temp=='-'||temp=='/'||temp=='*'){
			op=temp;
			//j--;
		}
		LCD_voidWriteData(op);
		//LCD_voidPrintStr("(2)");
	}
	
	i=0;
	//getting 2nd input:
	while(i<3){
		while(KP_getChar()==NOT_PRESSED){}
		temp=KP_getChar();
		_delay_ms(220);
		/*if(temp==TGL){
			return SW_resCalc();
		}*/
		if(temp>='0'&& temp<='9')
		{
			input2=input2*10 + (temp-'0');
			LCD_voidWriteData(temp);
			i++;
		}
		else if(temp=='='){
			LCD_voidWriteData('=');
			break;
		}
	}
	//LCD_voidPrintStr("(3)");
	if(temp!='='){
		LCD_voidWriteData('=');
	}
	switch(op){
		case '+': result= input1 + input2;break;
		case '-': result= input1 - input2;break;
		case '/': result= input1 / input2;break;
		case '*': result= input1 * input2;break;
		default: LCD_voidPrintStr("wrong operator");
	}
	LCD_voidPrintNum(result);
	return result;
}
