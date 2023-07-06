/*
 * ADC_prog.c
 *
 * Created: 6/17/2023 12:06:33 PM
 *  Author: Mayer
 */ 
#define F_CPU 16000000UL
#include "../../LIB/BIT_MATH.h"
#include "ADC_interface.h"
#include <util/delay.h>

static void (*pf_adc) (void);

void ADC_init(u8 ADC_ref,u8 AVD_preScalar, u8 trig_src)//inputs are ref and channel for vcc/vref... and channel type adc0/adc1...
{


	/* voltage reference selection */
	switch (ADC_ref)
	{
		case AREF:		CLR_BIT(ADMUX,REFS0);
						CLR_BIT(ADMUX,REFS1);
						break;
		case AVCC:		SET_BIT(ADMUX,REFS0);
						CLR_BIT(ADMUX,REFS1);
						break;
		case INT_VREF:	SET_BIT(ADMUX,REFS0);
						SET_BIT(ADMUX,REFS1);
						break;
	}
	
	/*left/right adjust(right by default)*/
	/*SET_BIT(ADMUX,ADLAR);*/
	
	/* ADPS2:0: ADC Prescaler Select Bits(64-128)*/
	ADCSRA &= 0b11111000;
	ADCSRA |= AVD_preScalar;
	
	/* ADEN: ADC Enable*/
	SET_BIT(ADCSRA,ADEN);
		/*– ADATE: ADC Auto Trigger Enable*/	/*SET_BIT(ADCSRA,ADATE);*/		/* ADIF: ADC Interrupt Flag*/	/*  Clear flag by setting to one, conversion finished flag */
	/*SET_BIT(ADCSRA,ADIF);*/  /* polling -> 1 */
	
	/* ADTS2:0: ADC Auto Trigger Source SFIOR REG */ 
/*
	SFIOR &= 0x1F; // Clear bits 5-7
	SFIOR |= ((trig_src & 0x07) << 5); // Set bits 5-7 based on variable*/
	}


/*ADIE: ADC Interrupt Enable*/
void ADCI_EN()
{
	SET_BIT(ADCSRA,ADIE);
}

void ADCI_DIS()
{
	CLR_BIT(ADCSRA,ADIE);
}

/* 
	a function to read ADC output
	output is analogue value		
	u8 ADC_channel
*/

/*
void ADC_read(u16 *ADC_result )
{
	*ADC_result=ADCL;
	*ADC_result=ADCH<<8; / *stored after the adcl to the left* /
}
*/

u16 ADC_read(u8 ADC_channel)
{
	
	/*select channel to read*/
	/*ADC_channel My_channel =CHANNEL_0+ADC_channel;*/
	ADMUX &= 0b11100000;
	ADMUX |= ADC_channel;
	
	/* ADSC: ADC Start Conversion*/	SET_BIT(ADCSRA,ADSC);
	
	/* polling ( waits for conversion to finish) */
	/*while(GET_BIT(ADCSRA,ADSC));
	SET_BIT(ADCSRA,ADIF);*/
	
	return ADCL;
}
void ADC_startConv(){
	/* ADSC: ADC Start Conversion*/	SET_BIT(ADCSRA,ADSC);
}

void callback_ADC(void (*function_name)(void))
{
	if (function_name!= NULL)
	{
		pf_adc=function_name;
	}

}

void __vector_16 (void) __attribute__((signal,used));

void __vector_16 (void)
{
	pf_adc();
}
/*
void AD_conv(){
	//AV(mv) = Reg * (5000UL/256);
}*/