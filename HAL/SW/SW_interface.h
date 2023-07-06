#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#include "SW_config.h"

#define BUZZ_PORT PORT_C
#define BUZZ_PIN PIN6

#define LOW		0
#define HIGH	1

#define OFF		0
#define ON		1

u8 SW_getSwSt(u8 PORTID,u8 UPINID);
//void sw_voidLED_ON(u8 PORTID, u8 PINID);


#endif /* SW_INTERFACE_H_ */