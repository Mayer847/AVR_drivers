#ifndef USART_INTERFACE_H_
#define USART_INTERFACE_H_

#define F_CPU 16000000UL
#include "USART_private.h"

/* UCSRA */
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* UCSRB */
#define RXCIE   7
#define TXCIE   6
#define UDRIE   5
#define RXEN    4
#define TXEN    3
#define UCSZ2   2
#define RXB8    1
#define TXB8    0

/* UCSRC */
#define URSEL   7
#define UMSEL   6
#define UPM1    5
#define UPM0    4
#define USBS    3
#define UCSZ1   2
#define UCSZ0   1
#define UCPOL   0

// Set baud rate to 9600
#define BAUD_RATE		9600
#define UBRR_VALUE		(((u32)F_CPU / (BAUD_RATE * 16UL)) - 1)

// Set frame format: 8 data bits, no parity, 1 stop bit
#define FRAME_FORMAT	((1 << UCSZ1) | (1 << UCSZ0))



void USART_init(void);
void USART_sendChar(u8 data);
u8 USART_receiveChar(void);
void USART_sendString(u8 *str, u8 len);

#endif /* UART_INTERFACE_H_ */