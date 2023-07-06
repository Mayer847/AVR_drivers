/*
 * TIMER_interface.h
 *
 * Created: 6/18/2023 10:43:25 AM
 *  Author: Mayer
 */ 
#include "TIMER0_private.h"

#ifndef TIMER0_INTERFACE_H_
#define TIMER0_INTERFACE_H_


/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0


/* TIMSK */
#define OCIE2   7
#define TOIE2   6
#define TICIE1  5
#define OCIE1A  4
#define OCIE1B  3
#define TOIE1   2
#define OCIE0   1
#define TOIE0   0


#define NORMAL   0
#define PWM		 1
#define CTC		 2
#define FAST_PWM 3


 
 #define NO_CLOCK		0
 #define NO_PRS			1
 #define PRS8			2
 #define PRS64			3
 #define PRS256			4
 #define PRS1024		5
 #define EXT_CLK_F		6
 #define EXT_CLK_R		7
 
 #define LOW	0
 #define HIGH	1

 
 #define NORM_OC0	0
 #define TGL_OC0	1
 #define CLR_OC0	2
 #define SET_OC0	3
 
 
 void TIMER0_init(u8 WGM_mode, u8 clock_select);
 void TIMER0_stop();
 void TIMER0_start(u8 clock_select);
 void TIMER0_callback(void (*function_name)(void));
 
void TIMER0_setDuty(u8 dutyCyclePercent);
void TIMER0_setComOutMOdeFast(u8 comOutFast);
void TIMER0_setComOutModeNon(u8 comOutNon);
void TIMER0_setCompareMatch(u8 compareMatchValue);
void TIMER0_preload(u8 preload_value);
void TIMER0_reset();
#endif /* TIMER_INTERFACE_H_ */