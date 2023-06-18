/*
 * LED_interface.h
 *
 * Created: 6/10/2023 9:53:06 PM
 *  Author: Mayer
 */ 


#ifndef LED_INTERFACE_H_
#define LED_INTERFACE_H_

void LED_voidON(u8 PORTID, u8 PINID);
void LED_voidOFF(u8 PORTID, u8 PINID);
void LED_voidTgl_LED(u8 PORTID, u8 PINID);

#endif /* LED_INTERFACE_H_ */