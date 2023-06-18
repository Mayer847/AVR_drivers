/*
 * TIMER_prog.c
 *
 * Created: 6/18/2023 10:45:00 AM
 *  Author: Mayer
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER_interface.h"

static void (*pf_tmr) (void);

void init_timer(u8 WGM_mode, u8 clock_select){
	
	SET_BIT(TIMSK_REG,TOIE0);
	
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
	/* ignore com01,com00	*/
}

void Timer_stop(){
	//CS02 CS01 CS00 => 000
	TCCR0_REG->TCCR0_CS0=NO_CLOCK;
}

void Timer_start(u8 clock_select){
	SET_BIT(TIMSK_REG,TOIE0);
	/* counter or timer? last three options in the table are for counter */
		switch(clock_select)
		{
			case NO_PRS:
			TCCR0_REG->TCCR0_CS0=1;
			case PRS8:
			TCCR0_REG->TCCR0_CS0=2;
			case PRS64:
			TCCR0_REG->TCCR0_CS0=3;
			case PRS256:
			TCCR0_REG->TCCR0_CS0=4;
			case PRS1024:
			TCCR0_REG->TCCR0_CS0=5;
			case EXT_CLK_F:
			TCCR0_REG->TCCR0_CS0=6;
			case EXT_CLK_R:
			TCCR0_REG->TCCR0_CS0=7;
		}
}

void callback_tmr(void (*function_name)(void))
{
	if (function_name!= NULL)
	{
		pf_tmr=function_name;
	}

}

void __vector_11 (void) __attribute__((signal,used));

void __vector_11 (void)
{
	
	pf_tmr();

}