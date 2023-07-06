/*
 * TIMER_prog.c
 *
 * Created: 6/18/2023 10:45:00 AM
 *  Author: Mayer
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER0_interface.h"
#include "../DIO/Dio_interface.h"
static void (*timer0_pf) (void);

void TIMER0_init(u8 WGM_mode, u8 clock_select){
	
	TIMSK_REG |= (1 << TOIE0);  // enable Timer0 overflow interrupt
	
	switch (WGM_mode)
	{
		case NORMAL:
			TCCR0_REG->TCCR0_WGM00=0;
			TCCR0_REG->TCCR0_WGM01=0;
			break;
		case PWM:
			TCCR0_REG->TCCR0_WGM00=1;
			TCCR0_REG->TCCR0_WGM01=0;
			break;
		case CTC:
			TCCR0_REG->TCCR0_WGM00=0;
			TCCR0_REG->TCCR0_WGM01=1;
			break;
		case FAST_PWM:
			TCCR0_REG->TCCR0_WGM00=1;
			TCCR0_REG->TCCR0_WGM01=1;
			break;
	}
	/*
	#if clock_select== NO_CLOCK
		TCCR0_REG->TCCR0_CS0=0;
	#elif clock_select == 
	#endif
	*/
	switch(clock_select)
	{
		case NO_CLOCK:
			TCCR0_REG->TCCR0_CS0=0;break;
		case NO_PRS:
			TCCR0_REG->TCCR0_CS0=1;break;
		case PRS8:
			TCCR0_REG->TCCR0_CS0=2;break;
		case PRS64:
			TCCR0_REG->TCCR0_CS0=3;break;
		case PRS256:
			TCCR0_REG->TCCR0_CS0=4;break;
		case PRS1024:
			TCCR0_REG->TCCR0_CS0=5;break;
		case EXT_CLK_F:
			TCCR0_REG->TCCR0_CS0=6;break;
		case EXT_CLK_R:
			TCCR0_REG->TCCR0_CS0=7;break;
	}
	if(WGM_mode==CTC || WGM_mode==FAST_PWM || WGM_mode==PWM)
	{
		Dio_voidSetPinDirection(PORT_B,PIN3,OUTPUT); /*e OC0 pin must be set in order to enable the output driver.*/
		/*Bit 5:4 – COM01:0: Compare Match Output Mode*/
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);/*OVERRIDES THE NORMAL PORT FUNCTIONALITY OF I/O PIN IT IS CONNECTED TO*/
	}
	
}

void TIMER0_setComOutModeNon(u8 comOutNon)
{
	Dio_voidSetPinDirection(PORT_B,PIN3,OUTPUT);
	switch(comOutNon)
	{
		case NORM_OC0:
			CLR_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);break;
		case TGL_OC0:	 
			SET_BIT(TCCR0,COM00);
			CLR_BIT(TCCR0,COM01);break;
		case CLR_OC0:	 
			CLR_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);break;
		case SET_OC0:	 
			SET_BIT(TCCR0,COM00);
			SET_BIT(TCCR0,COM01);break;
	}
}

void TIMER0_setDuty(u8 dutyCyclePercent) {
	OCR0 = (dutyCyclePercent * 255) / 100;
}

void TIMER0_setCompareMatch(u8 compareMatchValue)/* from 0 -> 255 */
{
	OCR0 = compareMatchValue; 
}

void TIMER0_preload(u8 preload_value)
{
	// Set Timer0 to normal mode
	/*TCCR0 &= ~(1 << WGM01);
	TCCR0 &= ~(1 << WGM00);*/

	// Set the preload value for Timer0
	TCNT0 = preload_value;
}
void TIMER0_reset()
{
	TCNT0=0;
}

void TIMER0_setComOutMOdeFast(u8 comOutFast)
{
	Dio_voidSetPinDirection(PORT_B,PIN3,OUTPUT);
	switch(comOutFast)
	{
		case NORM_OC0:
		CLR_BIT(TCCR0,COM00);
		CLR_BIT(TCCR0,COM01);break;
		case CLR_OC0:
		CLR_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);break;
		case SET_OC0:
		SET_BIT(TCCR0,COM00);
		SET_BIT(TCCR0,COM01);break;
	}
}

void TIMER0_stop()
{
	//CS02 CS01 CS00 => 000
	TCCR0_REG->TCCR0_CS0=NO_CLOCK;
	/*TCCR0&=0b11111000;*/
}

void TIMER0_start(u8 clock_select){
	/* counter or timer? last three options in the table are for counter */
		switch(clock_select)
		{
			case NO_PRS:
				TCCR0_REG->TCCR0_CS0=1;break;
			case PRS8:
				TCCR0_REG->TCCR0_CS0=2;break;
			case PRS64:
				TCCR0_REG->TCCR0_CS0=3;break;
			case PRS256:
				TCCR0_REG->TCCR0_CS0=4;break;
			case PRS1024:
				TCCR0_REG->TCCR0_CS0=5;break;
			case EXT_CLK_F:
				TCCR0_REG->TCCR0_CS0=6;break;
			case EXT_CLK_R:
				TCCR0_REG->TCCR0_CS0=7;break;
		}
}

void TIMER0_callback(void (*function_name)(void))
{
	if (function_name!= NULL)
	{
		timer0_pf=function_name;
	}

}

void __vector_11 (void) __attribute__((signal,used));

void __vector_11 (void)
{
	
	timer0_pf();

}