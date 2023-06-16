#define F_CPU 8000000UL	//define cpu 16 MHz clock external clock

#include <util/delay.h>
#include "../MCAL/DIO/Dio_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SW/SW_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/EXTI0/EXTI0_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
void EXTIO_counter();
void EXTI0_reset();
int main(void)
{
	/*call back function*/
	callback_pointer(&EXTIO_counter);

	/*initializing lcd & keypad			*/
	init_LCD();
	init_KP();
	
	//Setting SP7 pin to 1 in SREG
	gie_enable();//GLOBAL GIE, PREFERAL, FLAG
	//LCD_voidPrintStr("test1");
	//_delay_ms(1000);
	init_inti0();
	//LCD_voidPrintStr("test2");
	//_delay_ms(1000);
	//EXTI0_en();
	//LCD_voidPrintStr("test3");
	//_delay_ms(5000);
	//SW_u8Calc();
	while(1){
		
	}
}
static u8 counter=0;
void EXTIO_counter(){
	LCD_voidPrintStr("INTERRUPT0:");
	/*while(get_KP()==NOT_PRESSED){}
	if(get_KP()=='+')
	{
		counter++;
	}
	LCD_voidCls();*/
	counter++;
	LCD_voidPrintNum(counter);
}
void EXTI0_reset(){
	while(get_KP()==NOT_PRESSED){}
	if(get_KP()=='-')
	{
		counter=0;
	}
	LCD_voidCls();
	LCD_voidPrintNum(counter);
}
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