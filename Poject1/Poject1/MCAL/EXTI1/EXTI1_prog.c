 /*
 * EXTI1_prog.c
 *
 * Created: 6/17/2023 10:50:12 AM
 *  Author: Mayer
 */
  

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "../DIO/Dio_interface.h"
//#include "Dio_private.h"
#include "../../HAL/SW/SW_interface.h"
#include "../../HAL/SW/SW_config.h"
#include "EXTI1_interface.h"
#include "../GIE/GIE_interface.h"


static void (*pf_exti1) (void); //declaration of function to pointer name: pf * is pointer 

 //initializing external interrupt 1
 void init_inti1()
{
	//setting sense control mode:(rising edge):
	SET_BIT(MCUCR,PIN3);
	SET_BIT(MCUCR,PIN2);
	
	//Setting flag:
	SET_BIT(GIFR,6);
	
	//initializing input pin for interrupt1 pd3:
	Dio_voidSetPinDirection(PORT_D,PIN3,INPUT);
	Dio_voidSetPinValue(PORT_D,PIN3,HIGH);
}

void EXTI1_en()
{
	SET_BIT(GICR,7);
}
void EXTI1_dis()
{
	CLR_BIT(GICR,7);
}

void EXTI1_sensMode(u8 exti0_sensMode){
	switch (exti0_sensMode){
		case I1_LOW:CLR_BIT(MCUCR,PIN1);
			 CLR_BIT(MCUCR,PIN0);break;
		case I1_ANY:CLR_BIT(MCUCR,PIN1);
			 SET_BIT(MCUCR,PIN0);break;
		case I1_FALL:SET_BIT(MCUCR,PIN1);
			 CLR_BIT(MCUCR,PIN0);break;
		case I1_RISE:SET_BIT(MCUCR,PIN1);
			 SET_BIT(MCUCR,PIN0);break;
	}
}
//static *pointer;
void callback_exti1(void (*function_name)(void))
{
	if (function_name!= NULL)
	{
			pf_exti1=function_name;
	}

}

void __vector_2 (void) __attribute__((signal,used));

void __vector_2 (void) 
{
	
	pf_exti1();

}
