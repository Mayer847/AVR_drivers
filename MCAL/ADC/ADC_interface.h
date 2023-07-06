/*
 * ADC_interface.h
 *
 * Created: 6/17/2023 12:05:59 PM
 *  Author: Mayer
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_private.h"

#define AREF		0
#define AVCC		1
#define RES_VR		2
#define INT_VREF	3

/* ACSR */
#define ACD     7
#define ACBG    6
#define ACO     5
#define ACI     4
#define ACIE    3
#define ACIC    2
#define ACIS1   1
#define ACIS0   0

/* ADCSRA */
#define ADEN    7
#define ADSC    6
#define ADATE   5
#define ADIF    4
#define ADIE    3
#define ADPS2   2
#define ADPS1   1
#define ADPS0   0

/* ADMUX */
#define REFS1   7
#define REFS0   6
#define ADLAR   5
#define MUX4    4
#define MUX3    3
#define MUX2    2
#define MUX1    1
#define MUX0    0

#define ADC0	0
#define ADC1	1
#define ADC2	2
#define ADC3	3
#define ADC4	4
#define ADC5	5
#define ADC6	6
#define ADC7	7

#define DIV_FAC_2_0		0
#define DIV_FAC_2		1
#define DIV_FAC_4		2
#define DIV_FAC_8		3
#define DIV_FAC_16		4
#define DIV_FAC_32		5
#define DIV_FAC_64		6
#define DIV_FAC_128		7
						
#define FREERUN			0
#define ANALOGCOMP		1
#define EXTINT			2
#define TC0CM			3
#define TC0OV			4
#define TC1CMB			5
#define TC1OV			6
#define TC1CE			7


void ADC_init(u8 ADC_ref,u8 ADC_preScalar, u8 trig_src);
void ADCI_EN();
void ADCI_DIS();
u16 ADC_read(u8 ADC_channel);
void callback_ADC(void (*function_name)(void));
void ADC_startConv();
/*
typedef enum ADC_CHANNEL
{
	CHANNEL_0 = 0b00000000,
	CHANNEL_1 = 0b00000001,
	CHANNEL_2 = 0b00000010,
	CHANNEL_3 = 0b00000011,
	CHANNEL_4 = 0b00000100,
	CHANNEL_5 = 0b00000101,
	CHANNEL_6 = 0b00000110,
	CHANNEL_7 =0b00000111,
}ADC_channel;*/


#endif /* ADC_INT0b00000001ERFACE_H_ */