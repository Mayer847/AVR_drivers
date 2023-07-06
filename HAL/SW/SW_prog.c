#define F_CPU 16000000UL
#include <util/delay.h>
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../../MCAL/DIO/Dio_interface.h"
#include "SW_interface.h"


u8 SW_getSwSt(u8 PORTID,u8 PINID){
	
	u8 Local_PinVal = Dio_u8GetPinValue(PORTID,PINID);
	
	if(Local_PinVal==LOW)
		return ON;
	else
		return OFF;
}


/*
u8 SW_resCalc(){
	return SW_u8Calc();
}*/

/*void sw_voidLED_ON(u8 PORTID, u8 PINID){
	LED_voidON(PORTID,PINID); 
}
void sw_voidLED_OFF(u8 PORTID, u8 PINID){
	LED_voidOFF(PORTID,PINID);
}*/