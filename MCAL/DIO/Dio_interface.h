#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"
#include "Dio_private.h"

#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

#define PIN0 0
#define PIN1 1
#define PIN2 2
#define PIN3 3
#define PIN4 4
#define PIN5 5
#define PIN6 6
#define PIN7 7

#define OUTPUT 1
#define INPUT 0

#define HIGH 1
#define LOW 0

#define ON 1
#define OFF 0

/* PA7-PA0 = ADC7-ADC0 */
/* PORTA */
#define PA7     7
#define PA6     6
#define PA5     5
#define PA4     4
#define PA3     3
#define PA2     2
#define PA1     1
#define PA0     0

/* DDRA */
#define DDA7    7
#define DDA6    6
#define DDA5    5
#define DDA4    4
#define DDA3    3
#define DDA2    2
#define DDA1    1
#define DDA0    0

/* PINA */
#define PINA7   7
#define PINA6   6
#define PINA5   5
#define PINA4   4
#define PINA3   3
#define PINA2   2
#define PINA1   1
#define PINA0   0

/*
   PB7 = SCK
   PB6 = MISO
   PB5 = MOSI
   PB4 = SS#
   PB3 = OC0/AIN1
   PB2 = INT2/AIN0
   PB1 = T1
   PB0 = XCK/T0
 */

/* PORTB */
#define PB7     7
#define PB6     6
#define PB5     5
#define PB4     4
#define PB3     3
#define PB2     2
#define PB1     1
#define PB0     0

/* DDRB */
#define DDB7    7
#define DDB6    6
#define DDB5    5
#define DDB4    4
#define DDB3    3
#define DDB2    2
#define DDB1    1
#define DDB0    0

/* PINB */
#define PINB7   7
#define PINB6   6
#define PINB5   5
#define PINB4   4
#define PINB3   3
#define PINB2   2
#define PINB1   1
#define PINB0   0

/*
   PC7 = TOSC2
   PC6 = TOSC1
   PC1 = SDA
   PC0 = SCL
 */
/* PORTC */
#define PC7     7
#define PC6     6
#define PC5     5
#define PC4     4
#define PC3     3
#define PC2     2
#define PC1     1
#define PC0     0

/* DDRC */
#define DDC7    7
#define DDC6    6
#define DDC5    5
#define DDC4    4
#define DDC3    3
#define DDC2    2
#define DDC1    1
#define DDC0    0

/* PINC */
#define PINC7   7
#define PINC6   6
#define PINC5   5
#define PINC4   4
#define PINC3   3
#define PINC2   2
#define PINC1   1
#define PINC0   0

/*
   PD7 = OC2
   PD6 = ICP
   PD5 = OC1A
   PD4 = OC1B
   PD3 = INT1
   PD2 = INT0
   PD1 = TXD
   PD0 = RXD
 */

/* PORTD */
#define PD7     7
#define PD6     6
#define PD5     5
#define PD4     4
#define PD3     3
#define PD2     2
#define PD1     1
#define PD0     0

/* DDRD */
#define DDD7    7
#define DDD6    6
#define DDD5    5
#define DDD4    4
#define DDD3    3
#define DDD2    2
#define DDD1    1
#define DDD0    0

/* PIND */
#define PIND7   7
#define PIND6   6
#define PIND5   5
#define PIND4   4
#define PIND3   3
#define PIND2   2
#define PIND1   1
#define PIND0   0


void Dio_voidSetPinDirection(u8 PORTID, u8 PINID, u8 Direction);
void Dio_voidSetPinValue(u8 PORTID, u8 PINID, u8 Value);
u8   Dio_u8GetPinValue(u8 PORTID, u8 PINID);
void Dio_voidTogglePin(u8 PORTID, u8 PINID);
void Dio_voidSetPortValue(u8 PORTID, u8 Value);
void Dio_voidSetPortDirection(u8 PORTID, u8  Direction);

#endif /* MDIO_INTERFACE_H_ */
