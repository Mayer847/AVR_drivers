/*
 * TIMER1_prog.c
 *
 * Created: 6/19/2023 2:19:26 PM
 *  Author: Mayer
 */ 

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "TIMER1_interface.h"
#include "../DIO/Dio_interface.h"

void Timer1_init(u8 WGM_mode, u8 clock_select){
	
	/* Set the initial value of TCCR1A and TCCR1B to zero */
	TCCR1A = 0;
	TCCR1B = 0;
	
	/* Set the waveform generation mode (WGM) */
	TCCR1A |= (WGM_mode & 0x03); // Set WGM bits in TCCR1A
	TCCR1B |= ((WGM_mode & 0x0C) << 1); // Set WGM bits in TCCR1B
	
	/* Set the clock select (CS) */
	TCCR1B |= (clock_select & 0x07); // Set CS bits in TCCR1B
	
	/* Set the non-inverting output mode on OC1B pin */
	TCCR1A |= (1 << COM1B1); // Set COM1B1 bit in TCCR1A
	TCCR1A &= ~(1 << COM1B0); // Clear COM1B0 bit in TCCR1A
	
	/* Set the data direction of OC1B pin as output */
	DDRB_REG |= (1 << PIN2); // Set the third bit (PB2) of DDRB register to set the direction of OC1B pin as output
}


u16 Timer1_u16GetCounterValue(void)
{
	u16 Result;
	Result  = TCNT1L_REG;
	return Result;
}

void Timer1_Reset(void)
{
	TCNT1L_REG = 0;
	TCNT1H_REG = 0;
}
