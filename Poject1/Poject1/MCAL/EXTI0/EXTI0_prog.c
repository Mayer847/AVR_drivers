/*
 * EXTI0_prog.c
 *
 * Created: 6/16/2023 11:18:36 AM
 *  Author: Mayer
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/Dio_interface.h"
//#include "Dio_private.h"
#include "../../HAL/SW/SW_interface.h"
#include "../../HAL/SW/SW_config.h"
#include "EXTI0_interface.h"
#include "../GIE/GIE_interface.h"


static void (*pf_exti0) (void); //declaration of function to pointer name: pf * is pointer 

void init_inti0(){//init is always in config pre-built use config .h
	Dio_voidSetPinDirection(PORT_D,PIN2,INPUT);
	Dio_voidSetPinValue(PORT_D,PIN2,HIGH);
	//gie_enable();
	SET_BIT(MCUCR,PIN1);//falling edge
	CLR_BIT(MCUCR,PIN0);
	//SET_BIT(GICR,6);
	//CLR_BIT(GIFR,6);
	SET_BIT(GIFR,6);//reset FLAG by setting it to 1 (  set by clearing bit to zero)
}

void EXTI0_en(){
	SET_BIT(GICR,6);
}
void EXTI0_dis(){
	CLR_BIT(GICR,6);
}

void EXTI0_sensMode(u8 exti0_sensMode){
	switch (exti0_sensMode){
		case I0_LOW:CLR_BIT(MCUCR,PIN1);
			 CLR_BIT(MCUCR,PIN0);break;
		case I0_ANY:CLR_BIT(MCUCR,PIN1);
			 SET_BIT(MCUCR,PIN0);break;
		case I0_FALL:SET_BIT(MCUCR,PIN1);
			 CLR_BIT(MCUCR,PIN0);break;
		case I0_RISE:SET_BIT(MCUCR,PIN1);
			 SET_BIT(MCUCR,PIN0);break;
	}
}
//static *pointer;
void callback_exti0(void (*function_name)(void))
{
	if (function_name!= NULL)
	{
			pf_exti0=function_name;
	}

}

void __vector_1 (void) __attribute__((signal,used));

void __vector_1 (void) 
{
	
	pf_exti0();

}


