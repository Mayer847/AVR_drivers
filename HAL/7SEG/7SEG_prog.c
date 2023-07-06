/*
 * _7SEG_prog.c
 *
 * Created: 6/10/2023 11:15:48 PM
 *  Author: Mayer
 */ 
#include "../../MCAL/DIO/Dio_interface.h"

void seg_init(){
	/*set pins as output*/
	Dio_voidSetPinDirection(PORT_B,PIN0, OUTPUT);
	Dio_voidSetPinDirection(PORT_B,PIN1, OUTPUT);
	Dio_voidSetPinDirection(PORT_B,PIN2, OUTPUT);
	Dio_voidSetPinDirection(PORT_B,PIN4, OUTPUT);
	
	
	Dio_voidSetPinDirection(PORT_A,PIN3, OUTPUT);
	Dio_voidSetPinDirection(PORT_A,PIN2, OUTPUT);
	Dio_voidSetPinDirection(PORT_B,PIN5, INPUT);
	Dio_voidSetPinDirection(PORT_B,PIN6, INPUT);


	Dio_voidSetPinValue(PORT_A,PIN3, HIGH);		//OFF COMMON ANODE
	Dio_voidSetPinValue(PORT_A,PIN2, HIGH);
}

void seg_dispNum(s8 num_input){
	
}