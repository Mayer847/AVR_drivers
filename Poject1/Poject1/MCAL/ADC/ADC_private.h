/*
 * ADC_private.h
 *
 * Created: 6/17/2023 12:06:17 PM
 *  Author: Mayer
 */ 

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"

#define ADMUX *((volatile u8*) 0x27)
#define ADCSRA *((volatile u8*) 0x26)
#define ADCH *((volatile u8*) 0x25)
#define ADCL *((volatile u16*) 0x24)//read from this 16 bits
 


#endif /* ADC_PRIVATE_H_ */