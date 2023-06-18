/*
 * GIE_prog.c
 *
 * Created: 6/16/2023 2:41:55 PM
 *  Author: Mayer
 */ 
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "GIE_config.h"
#include "GIE_private.h"
void gie_enable(){
	SET_BIT(S_REG,7);
}
void gie_disable(){
	CLR_BIT(S_REG,7);
}