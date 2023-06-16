/*
 * SW_interface.h
 *
 * Created: 6/10/2023 11:14:34 PM
 *  Author: Mayer
 */ 


#ifndef SW_INTERFACE_H_
#define SW_INTERFACE_H_

#include "SW_config.h"

#define BUZZ_PORT PORT_C
#define BUZZ_PIN PIN6


u8 get_u8SwSt(u8 PORTID,u8 UPINID);
//void sw_voidLED_ON(u8 PORTID, u8 PINID);

void init_KP();
u8 get_KP();
void password();
u8 SW_u8Calc();

#endif /* SW_INTERFACE_H_ */