/*
 * ADC_prog.c
 *
 * Created: 6/17/2023 12:06:33 PM
 *  Author: Mayer
 */ 
#include "../../LIB/BIT_MATH.h"
#include "ADC_interface.h"

static void (*pf_adc) (void);

void init_ADC(u8 ADC_ref,u8 AVD_preScalar)//inputs are ref and channel for vcc/vref... and channel type adc0/adc1...
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
	//SET_BIT(ADMUX,ADLAR);
	
	/* ADEN: ADC Enable*/
	SET_BIT(ADCSRA,ADEN);
		/*– ADATE: ADC Auto Trigger Enable*/	CLR_BIT(ADCSRA,ADATE);		/*ADIF: ADC Interrupt Flag*/	/* Clear flag by setting to one, conversion finished flag*/
	SET_BIT(ADCSRA,ADIF);//polling -> 1
	
	/*ADPS2:0: ADC Prescaler Select Bits(128)*/
	SET_BIT(ADCSRA,ADPS2);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS0);
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
	/*ADC_channel My_channel =CHANNEL_0+ADC_channelCpy;*/
	ADMUX &= 0b11100000;
	ADMUX |= ADC_channel;
	
	/* ADSC: ADC Start Conversion*/	SET_BIT(ADCSRA,ADSC);
	
	/* polling */

	//while(GET_BIT(ADCSRA,ADSC));

	return ADCL;
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