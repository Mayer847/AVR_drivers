#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

#include "TIMER1_private.h"

#define	NORM_PWM			0
#define PWM_8				1
#define	PWM_9				2
#define	PWM_10				3
#define	CTC_T1_0			4
#define	FAST_8				5
#define	FAST_9				6
#define	FAST_10				7
#define PWM_PF_C_0			8
#define PWM_PF_C_1			9
#define PWM_P_C_0			10
#define	PWM_P_C_1			11
#define	CTC_T1_1			12
#define RES					13
#define	FAST_PWM_0			14
#define	FAST_PWM_1			15

/* TCCR1A */
#define COM1A1				7		/*NORMAL ,, ...*/
#define COM1A0				6
#define COM1B1				5
#define COM1B0				4
#define FOC1A				3
#define FOC1B				2
#define WGM11				1
#define WGM10				0 

/* TCCR1B */
#define ICNC1				7
#define ICES1				6
/* bit 5 reserved */
#define WGM13				4
#define WGM12				3
#define CS12				2
#define CS11				1
#define CS10				0


#define NORMAL_OP			0
#define TGL_OC				1
#define CLEAR_OC			2
#define SET_OC				3


 void Timer1_init(u8 WGM_mode, u8 clock_select);
 u16 Timer1_u16GetCounterValue(void);
 void Timer1_Reset(void);
 void tmr1_callback(void (*function_name)(void));


#endif /* TIMER1_INTERFACE_H_ */