/*
 * EXTI0_interface.h
 *
 * Created: 6/16/2023 11:20:13 AM
 *  Author: Mayer
 */ 

#ifndef EXTI0_INTERFACE_H_
#define EXTI0_INTERFACE_H_

#include "EXTI0_private.h"

#define I0_LOW		0
#define I0_ANY		1
#define I0_FALL		2
#define I0_RISE		3

void EXTI0_init();
void EXTI0_en();
void EXTI0_dis();
void EXTI0_sensMode(u8 exti0_sensMode);
void callback_exti0(void (*func_address)(void));


#endif /* EXTI0_INTERFACE_H_ */