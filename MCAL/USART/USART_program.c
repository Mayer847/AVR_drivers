#include "USART_interface.h"


// Configure USART for UART communication
void USART_init(void){
	  // Set baud rate
	  //UBRRH = (u8)(UBRR_VALUE >> 8); // Write high byte to UBRRH
	  UBRRL = (u8)UBRR_VALUE; // Write low byte to UBRRL

	  // Set frame format
	  UCSRC = (1 << URSEL) | FRAME_FORMAT; // Write frame format to UCSRC

	  // Enable receiver and transmitter
	  UCSRB = (1 << RXEN) | (1 << TXEN);
}

void USART_sendChar(u8 data){
	// Wait for the transmit buffer to be empty
	while (!(UCSRA & (1 << UDRE)));

	// Send the data
	UDR = data;
}
u8 USART_receiveChar(void)
{
	// Wait for data to be received
	while (!(UCSRA & (1 << RXC)));

	// Return received data
	return UDR;
}

void USART_sendString(u8 *str, u8 len)
{
	// Send each character in the string
	for (u8 i = 0; i < len; i++) {
		// Wait for the transmit buffer to be empty
		while (!(UCSRA & (1 << UDRE)));

		// Send the character
		UDR = str[i];
	}
}