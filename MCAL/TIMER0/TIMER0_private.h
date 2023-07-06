#ifndef TIMER_PRIVATE_H_
#define TIMER_PRIVATE_H_

#define TCNT0		*((volatile u8*)		 0x52) //preload value for remainder (ctc)
#define	TCCR0		*((volatile u8*)		 0x53)
#define	TCCR0_REG	 ((volatile TCCR0_R*)	 0x53)
//#define TCNT0_REG *((volatile u8*)		 0x52)
#define TIMSK_REG	*((volatile u8*)		 0x59)
#define OCR0		*((volatile u8*)		 0x5C)



typedef struct
{
	u8 TCCR0_CS0   :3; // THREE PLACES ARE RESERVED FOR IT IN MEMORY CS FROM 0 TO 3
	u8 TCCR0_WGM01 :1;
	u8 TCCR0_COM00 :2;
	u8 TCCR0_WGM00 :1;
	u8 TCCR0_FOC0  :1;
	
}TCCR0_R;


#endif /* TIMER_PRIVATE_H_ */