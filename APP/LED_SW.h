/*
 * LED_SW.h
 *
 * Created: 6/20/2023 8:15:36 AM
 *  Author: Mayer
 */ 


#ifndef LED_SW_H_
#define LED_SW_H_


/*copy to main*/
/*
Dio_voidSetPinDirection(u8 PORTID, u8 PINID, u8 Direction);
Dio_voidSetPinValue(u8 PORTID, u8 PINID, u8 Value);
Dio_u8GetPinValue(u8 PORTID, u8 PINID);
Dio_voidTogglePin(u8 PORTID, u8 PIND);
Dio_voidSetPortValue(u8 PORTID, u8 Value);
Dio_voidSetPortDirection(u8 PORTID, u8  Direction);*/

/******direct SWITCH LED *******/

void LED_SW_test(){
	LED_voidON(PORT_A,PIN4);
	_delay_ms(1000);
	LED_voidOFF(PORT_A,PIN4);
	_delay_ms(1000);

	if(SW_getSwSt(PORT_D,PIN7)==ON){
		LED_voidON(PORT_A,PIN4);
		_delay_ms(500);
	}
	else if(SW_getSwSt(PORT_D,PIN7)==OFF){
		LED_voidOFF(PORT_A,PIN4);
		//_delay_ms(1000);
	}
	
}

//Dio_voidSetPinDirection(PORT_C,PIN1,OUTPUT);




#endif /* LED_SW_H_ */