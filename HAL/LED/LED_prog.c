/*
 * LED_prog.h
 *
 * Created: 6/10/2023 9:53:42 PM
 *  Author: Mayer
 */ 


#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/Dio_interface.h"
#include "../../MCAL/DIO/Dio_private.h"
#include "LED_interface.h"
#include "LED_private.h"


void LED_voidON(u8 PORTID, u8 PINID){
	Dio_voidSetPinDirection(PORTID,PINID,OUTPUT);
	Dio_voidSetPinValue(PORTID,PINID,ON);
}

void LED_voidOFF(u8 PORTID, u8 PINID){
	Dio_voidSetPinDirection(PORTID,PINID,OUTPUT);
	Dio_voidSetPinValue(PORTID,PINID,OFF);
}

void LED_voidTgl_LED(u8 PORTID, u8 PINID){
	Dio_voidSetPinDirection(PORTID,PINID,OUTPUT);
	Dio_voidTogglePin(PORTID,PINID);
}
