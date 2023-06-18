/*define cpu 16 MHz clock external clock*/
#define F_CPU 16000000UL	
/*delay*/
#include <util/delay.h>
/*MCAL*/
#include "../MCAL/DIO/Dio_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXTI0/EXTI0_interface.h"
#include "../MCAL/EXTI1/EXTI1_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"
/*HAL*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SW/SW_interface.h"
#include "../HAL/LCD/LCD_interface.h"

/*prototypes*/
void EXTI1_counter();
void ADC_LDR();
void led_tmr();
/*void EXTI1_reset();*/

/*global variables*/
static u8 cntFlag=0;
static u8 counter=0;
static u16 LDR_reading=0;
static u8 tmr_count=0;
static u8 temp=0;

int main(void)
{
/**************** SETTING PIN DIRECTION **********/

	/*LED*/
	Dio_voidSetPinDirection(PORT_A,PIN4,OUTPUT);
	
	/*LDR*/
	Dio_voidSetPinDirection(PORT_A,PIN0,INPUT);
	
/**************** INITIALIZATION ****************/

	/*LCD & keypad*/
	init_LCD();
	init_KP();
	
	/*ADC*/
	init_ADC(1,0);
	
	/*TIMER*/
	init_timer(NORMAL,PRS1024);

/******************* INTERRUPTS ******************/	

/*Enable all interrupts*/
	gie_enable();//GLOBAL GIE, PREFERAL, FLAG, Setting SP7 pin to 1 in SREG	
	
/*external interrupts*/
	
	/*init_inti0();*/
	init_inti1();
	
/*ADC interrupts*/
	ADCI_EN();
	
/*call back functions*/
	callback_tmr(&led_tmr);
	callback_exti1(&EXTI1_counter);
	/*callback_exti1(&EXTI1_reset);*/ //H.W*****
	/*callback_ADC(&ADC_LDR);*/

	
/*enabling GICR for interrupts*/
	
	/*EXTI0_en();*/	//H.W***********
	EXTI1_en();

/******************	TESTING ******************/

/*LCD TESTS*/
	
	/*LCD_voidPrintStr("test123");
	_delay_ms(500);
	LCD_voidCls();
	LCD_voidPrintNum(71);*/
	
	
/* ADC polling */ //H.W
	/*LCD_voidPrintNum(ADC_read(ADC0));*/
	
/* interrupt 1 counter '+' switch(Row 4, col 4)*/
	while(1){
		if(cntFlag==1){
			temp=get_KP();
			if(temp=='+')
			{
				LCD_voidCls();
				counter++;
				LCD_voidPrintNum(counter);
			}
/* start timer with external interrupt one using '*' switch */
			else if (temp == '*')
			{
				Timer_start(PRS1024);
			}
			else if (temp== '/')
			{
				Dio_voidSetPinValue(PORT_A,PIN4,LOW);
				Timer_stop();
			}
		}
		
/* Timer LED Toggle every 1 second */
		if(tmr_count==61){
			Dio_voidSetPinValue(PORT_A,PIN4,HIGH);
		}
		if(tmr_count==122){
			tmr_count=0;
			Dio_voidSetPinValue(PORT_A,PIN4,LOW);
		}
	}
}

void ADC_LDR(){
	LDR_reading= (5000UL* (u64) ADC_read(ADC0))/1024;/* casting because number is too big */
	LCD_voidCls();
	LCD_voidPrintNum(LDR_reading);
	_delay_ms(200);
}

void led_tmr()
{
	tmr_count++;
}

void EXTI1_counter()
{
	cntFlag=1;
}

/*
void EXTI1_reset(){
	while(get_KP()==NOT_PRESSED){}
	if(get_KP()=='-')
	{
		counter=0;
	}
	LCD_voidCls();
	LCD_voidPrintNum(counter);
}*/


/*Dio_voidSetPinDirection(u8 PORTID, u8 PINID, u8 Direction);
Dio_voidSetPinValue(u8 PORTID, u8 PINID, u8 Value);
Dio_u8GetPinValue(u8 PORTID, u8 PINID);
Dio_voidTogglePin(u8 PORTID, u8 PIND);
Dio_voidSetPortValue(u8 PORTID, u8 Value);
Dio_voidSetPortDirection(u8 PORTID, u8  Direction);*/

/******direct SWITCH LED *******/

/*LED_voidON(PORT_A,PIN4);//how does it know PORTA in microcontroller? 
		_delay_ms(1000);
		LED_voidOFF(PORT_A,PIN4);
		_delay_ms(1000);
		
		if(get_u8SwSt(PORT_D,PIN7)==ON){
			LED_voidON(PORT_A,PIN4);
			_delay_ms(500);
		}
		else if(get_u8SwSt(PORT_D,PIN7)==OFF){
			LED_voidOFF(PORT_A,PIN4);
			//_delay_ms(1000);
		}*/

//Dio_voidSetPinDirection(PORT_C,PIN1,OUTPUT);
	
//  	init_LCD();
//  	LCD_voidCls();
	/*LCD_voidWriteData('B');
	_delay_ms(10);
	LCD_voidWriteData('O');
	_delay_ms(10);
	LCD_voidWriteData('B');
	_delay_ms(10);
	*/
	//init_KP();
	//password();
	//password();
	//u8 integer=196;
	//LCD_voidPrintNum(integer);
	//SW_u8Calc();
	//u8 input;
	//init_KP();
	//LCD_voidCls();
// 	while(1){
// 		input=get_KP();
// 		if(input!=0xff){
// 			//LCD_voidCommand(0xc0);
// 			_delay_ms(250);
// 			LCD_voidWriteData(input);
// 		}	
// 	}