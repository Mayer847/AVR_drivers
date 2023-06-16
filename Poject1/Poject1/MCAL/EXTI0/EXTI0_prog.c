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


#define		NULL		((void *)0)
static void (*pf) (void); //declaration of function to pointer name: pf * is pointer 

void init_inti0(){//init is always in config pre-built use config .h
	Dio_voidSetPinDirection(PORT_D,PIN2,INPUT);
	Dio_voidSetPinValue(PORT_D,PIN2,HIGH);
	//gie_enable();
	SET_BIT(MCUCSR,PIN1);//falling edge
	CLR_BIT(MCUCSR,PIN0);
	SET_BIT(GICR,6);
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
		case LOW:CLR_BIT(MCUCSR,PIN1);
			 CLR_BIT(MCUCSR,PIN0);break;
		case ANY:CLR_BIT(MCUCSR,PIN1);
			 SET_BIT(MCUCSR,PIN0);break;
		case FALL:SET_BIT(MCUCSR,PIN1);
			 CLR_BIT(MCUCSR,PIN0);break;
		case RISE:SET_BIT(MCUCSR,PIN1);
			 SET_BIT(MCUCSR,PIN0);break;
	}
}
//static *pointer;
void callback_pointer(void (*function_name)(void))
{
	if (function_name!= NULL)
	{
			pf=function_name;
	}

}

void __vector__1 (void) __attribute__((signal,used));

void __vector__1 (void) 
{
	
	pf();

}


