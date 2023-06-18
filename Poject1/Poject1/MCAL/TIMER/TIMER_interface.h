/*
 * TIMER_interface.h
 *
 * Created: 6/18/2023 10:43:25 AM
 *  Author: Mayer
 */ 
#include "TIMER_private.h"

#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_


/* TCCR0 */
#define FOC0    7
#define WGM00   6
#define COM01   5
#define COM00   4
#define WGM01   3
#define CS02    2
#define CS01    1
#define CS00    0

/* TCCR2 */
#define FOC2    7
#define WGM20   6
#define COM21   5
#define COM20   4
#define WGM21   3
#define CS22    2
#define CS21    1
#define CS20    0

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
 
 #define HIGH	1
 #define LOW	0
 
 
 void init_timer(u8 WGM_mode, u8 clock_select);
 void Timer_stop();
 void Timer_start(u8 clock_select);
 void callback_tmr(void (*function_name)(void));

#endif /* TIMER_INTERFACE_H_ */