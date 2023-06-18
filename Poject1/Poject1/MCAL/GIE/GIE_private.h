/*
 * in r16, SREG ; store SREG value
 cli ; disable interrupts during timed sequence
 sbi EECR, EEMWE ; start EEPROM write
 sbi EECR, EEWE
 out SREG, r16 ; restore SREG value (I-bit)
 */ 


#ifndef GIE_PRIVATE_H_
#define GIE_PRIVATE_H_


#define S_REG *((volatile u8*) 0x5f)


#endif /* GIE_PRIVATE_H_ */