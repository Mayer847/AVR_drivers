/*
 * EXTI1_interface.h
 *
 * Created: 6/17/2023 9:00:29 AM
 *  Author: Mayer
 */ 


#ifndef EXTI1_INTERFACE_H_
#define EXTI1_INTERFACE_H_


#include "EXTI1_private.h"

#define I1_LOW		0
#define I1_ANY		1
#define I1_FALL		2
#define I1_RISE		3

void init_inti1();
void EXTI1_en();
void EXTI1_dis();
void EXTI1_sensMode(u8 exti0_sensMode);
void callback_exti1(void (*func_address)(void));




#endif /* EXTI1_INTERFACE_H_ */