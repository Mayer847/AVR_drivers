
/*
 * EXTI0_private.h
 *
 * Created: 6/16/2023 11:19:09 AM
 *  Author: Mayer
 */ 


#ifndef EXTI0_PRIVATE_H_
#define EXTI0_PRIVATE_H_

#define MCUCR *((volatile u8*) 0x55)
#define GICR *((volatile u8*) 0x5b)
#define GIFR *((volatile u8*) 0x5a)


/*
#define SE 0b1000000

#define INT0_LOW	0b00000000
#define INT0_ANY	0b00000001
#define INT0_FALL	0b00000010
#define INT0_RISE	0b00000011

*/


#endif /* EXTI0_PRIVATE_H_ */