
#include "SPI_interface.h"
#include "../DIO/Dio_interface.h"


/*
void spi_init(void)
{
	/ *
	 *MOSI: master output slave input data pin
	 *SCK : serial clock for data sync
	 *SS' : slave select pin
	 * /
	/ * Set MOSI, SCK, and SS as output pins * /
	DDRB_REG |= (1 << DDB3) | (1 << DDB5) | (1 << DDB2);

	/ * Enable SPI, set as master, and set clock rate to F_CPU/128 * /
	SPCR |= (1 << SPE) | (1 << MSTR) | (1 << SPR1) | (1 << SPR0);

	/ * Clear SPIF flag in SPSR by reading SPI status register and data register * /
	u8 dummy = SPDR; / *clear the SPDR register after a data transfer is completed* /
	(void)dummy;
}*/

// Initialize SPI module in master mode
void SPI_MasterInit() 
{
	// Set MOSI, SCK, and SS pins as output pins
	DDRB_REG |= (1 << DDB3) | (1 << DDB5) | (1 << DDB2);
	// Set MISO pin as input pin
	DDRB_REG &= ~(1 << DDB4);
	// Enable SPI module, set as master, and set clock rate to fosc/16
	SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

// Transmit data from master device
void SPI_MasterTransmit(u8 data) 
{
	// Load data into SPI data register
	SPDR = data;
	// Wait for transmission to complete
	while (!(SPSR & (1 << SPIF)));
}

// Initialize SPI module in slave mode
void SPI_SlaveInit() 
{
	// Set MOSI, SCK, and SS pins as input pins
	DDRB_REG &= ~((1 << DDB3) | (1 << DDB5) | (1 << DDB2));
	// Set MISO pin as output pin
	DDRB_REG |= (1 << DDB4);
	// Enable SPI module, set as slave
	SPCR = (1 << SPE);
}

// Receive data on slave device
u8 SPI_SlaveReceive() 
{
	// Wait for data to be received
	while (!(SPSR & (1 << SPIF)));
	// Read data from SPI data register
	return SPDR;
}