#ifndef USART_PRIVATE_H_
#define USART_PRIVATE_H_

#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"

#define UDR			*((volatile u8*) 0x2C)
#define UCSRA		*((volatile u8*) 0x2B)
#define UCSRB		*((volatile u8*) 0x2A)
#define UCSRC		*((volatile u8*) 0x40)
#define UBRRH		*((volatile u8*) 0x40)
#define UBRRL		*((volatile u8*) 0x29)



#endif /* UART_PRIVATE_H_ */