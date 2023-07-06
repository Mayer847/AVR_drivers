#ifndef TIMER1_PRIVATE_H_
#define TIMER1_PRIVATE_H_
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"


#define TCCR1A	*((volatile u8*) 0x4f)
#define TCCR1B  *((volatile u8*) 0x4e)

#define TCNT1H_REG    *((volatile u8*) 0x4D)
#define TCNT1L_REG    *((volatile u16*) 0x4C)
#define OCR1AH_REG    *((volatile u8*) 0x4B)
#define OCR1AL_REG    *((volatile u16*) 0x4A)
#define OCR1BH_REG    *((volatile u8*) 0x49)
#define OCR1BL_REG    *((volatile u16*) 0x48)
#define ICR1L_REG     *((volatile u8*) 0x47)
#define ICR1H_REG     *((volatile u8*) 0x46)
#define TIMSK_REG     *((volatile u8*) 0x59)
#define TIFR_REG      *((volatile u8*) 0x58)



#endif /* TIMER1_PRIVATE_H_ */