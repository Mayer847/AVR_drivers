#ifndef SPI_INTERFACE_H_
#define SPI_INTERFACE_H_

#include "../../LIB/STD_TYPES.h"
#include "SPI_private.h"

/* Bit Definitions for SPCR Register */
#define SPIE    7
#define SPE     6
#define DORD    5
#define MSTR    4
#define CPOL    3
#define CPHA    2
#define SPR1    1
#define SPR0    0

/* Bit Definitions for SPSR Register */
#define SPIF    7
#define WCOL    6
#define SPI2X   0


void SPI_MasterInit();
void SPI_MasterTransmit(u8 data);
void SPI_SlaveInit();
u8 SPI_SlaveReceive();

#endif /* SPI_INTERFACE_H_ */