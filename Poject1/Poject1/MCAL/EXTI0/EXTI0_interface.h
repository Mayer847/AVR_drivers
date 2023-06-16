/*
 * EXTI0_interface.h
 *
 * Created: 6/16/2023 11:20:13 AM
 *  Author: Mayer
 */ 

#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_

#include "EXTI0_private.h"

#define LOW		0
#define ANY		1
#define FALL	2
#define RISE	3

void init_inti0();
void EXTI0_en();
void EXTI0_dis();
void EXTI0_sensMode(u8 exti0_sensMode);
void callback_pointer(void (*func_address)(void));


#endif /* EXTI0_INTERFACE_H_ */