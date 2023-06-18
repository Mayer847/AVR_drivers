#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_
#include "../../LIB/STD_TYPES.h"

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

void Dio_voidSetPinDirection(u8 PORTID, u8 PINID, u8 Direction);
void Dio_voidSetPinValue(u8 PORTID, u8 PINID, u8 Value);
u8   Dio_u8GetPinValue(u8 PORTID, u8 PINID);
void Dio_voidTogglePin(u8 PORTID, u8 PINID);
void Dio_voidSetPortValue(u8 PORTID, u8 Value);
void Dio_voidSetPortDirection(u8 PORTID, u8  Direction);

#endif /* MDIO_INTERFACE_H_ */
