/*define cpu 16 MHz clock external clock*/
#define F_CPU 16000000UL	
/*delay*/
#include <util/delay.h>
/*MCAL*/
#include "../MCAL/DIO/Dio_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/EXTI0/EXTI0_interface.h"
#include "../MCAL/EXTI1/EXTI1_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/TIMER0/TIMER0_interface.h"
#include "../MCAL/TIMER1/TIMER1_interface.h"
#include "../MCAL/USART/USART_interface.h"
#include "../MCAL/SPI/SPI_interface.h"
/*HAL*/
#include "../HAL/LED/LED_interface.h"
#include "../HAL/SW/SW_interface.h"
#include "../HAL/KP/KP_interface.h"
#include "../HAL/LCD/LCD_interface.h"

/*APP (FUNCTIONS) */
#include "Lcd_kp.h"
#include "Timer0.h"
#include "Extint.h"
/*#include "ADC.h"
#include "Hamoksha.h"*/
#include "watch_alarm.h"
#include "ICU.h"


int main(void)
{
/**************** SETTING PIN DIRECTION **********/

	Dio_voidSetPinDirection(PORT_A,PIN4,OUTPUT);/* LED */
	Dio_voidSetPinDirection(PORT_A,PIN0,INPUT);/* LDR ADC0 */
	Dio_voidSetPinDirection(PORT_A,PIN1,INPUT);/* LDR ADC1 */
	Dio_voidSetPinDirection(PORT_C,PIN6,OUTPUT);/* BUZZER */
	Dio_voidSetPinDirection(PORT_B,PIN3,OUTPUT);/* CTC or FAST WPM */
	
/**************** INITIALIZATION ****************/
	/*LCD & keypad*/
	LCD_init();
	KP_init();
	
	/*ADC*/
	/*ADC_init(AVCC,DIV_FAC_128,FREERUN);*/	/*50-250*/
	
	/*TIMER*/
	/*counting 1 second using NORMAL mode and preload value */
	/*TIMER0_init(NORMAL,PRS1024);*/	//16.384ms, nov=61.035, preload= 0.035*256 = 9 /* needs debugging */ 
	/*TIMER0_preload(9);*/				//9-> 7.7 secondds (5), 247->
	/*counting 1 second using CTC & compare match */	
	TIMER0_init(CTC,PRS1024);	
	//TIMER0_setCompareMatch(170);	/* to count 1 second, tick time = 64 micros, 64 micro x 250 = 16 ms */
	TIMER0_preload(144);			/* nov= 1s / 16 millis = 1/16millis = 62.5, preload value? = 128 (1/2) (tccn0)*/ 
	/*preload value = 256 - (clock frequency * time delay / prescaler)
	*/
	/*Timer0_init(PWM,PRS8);
	Timer0_setDuty(50);*/
	
	/*Timer1_init(FAST_PWM,PRS1024);*/ 
	/*Timer1_init(NORMAL,PRS8);*/
	
/******************* INTERRUPTS ******************/	

/*Enable all interrupts( GLOBAL)*/
	GIE_enable();
	
/*external interrupts*/
	/*EXTI0_init();*/
	EXTI1_init();
	
/*ADC interrupts*/
	/*ADCI_EN();*/
	
/*call back functions*/
	EXTI1_callback(&EXTI1_ISR);
	/*callback_ADC(&ADC_flag);*/
	TIMER0_callback(&TIMER0_ISR);
	
/*enabling interrupts (GICR)*/
	/*EXTI0_en();*/	/*under development*/
	EXTI1_en();

/******************	TESTING ******************/

/* LCD & KP tests */
	/*Lcd_kp_tests();*/
	/*KP_password();*/		/* password is 1234 */
	/*KP_u8SimpleCalc();*/
	
	
/* watch alarm */
	/* enable: timer0 & exti0 interrupts */
	/* initialize timer0: PreScalar= 1024, Normal: pre-load=9, CTC: compare match=250? */
	/*watch_alarm();*/
	
/* testing ICU simulator*/
	/* hardwire timer0 with EXTI1 pin */
	/* use timer1 as counter */
	/* init timer0 & timer1 with same prescaler ex.prs8 */
	/*ICU();*/
	//Dio_voidSetPinValue(PORT_A,PIN4,HIGH);
	
/* USART TESTING */
	/* USART initialize */
	/*USART_init();*/
	
	/*USART: Send a character & string*/
	/*u8 str1[] = "type 1 to turn on LED";
	u8 str2[] = "type 2 to turn on BUZZER";
	u8 len1 = sizeof(str1) - 1; // exclude null terminator
	u8 len2 = sizeof(str2) - 1;
	USART_sendChar('*');
	USART_sendString(str1, len1);
	USART_sendChar('*');
	USART_sendString(str2, len2);*/
	
/* SPI TESTING */
	/* SPI initialize as master */
	/*SPI_MasterInit();*/
	/* SPI: send data */
	/*SPI_MasterTransmit('L');*/
	
/* Wait for transmission to complete */
	/* while (!(SPSR & (1 << SPIF)));*/
	 
/* Initialize SPI module in slave mode */
	/*SPI_SlaveInit();*/
	
	while(1){
	/* SPI: receive data from virtual terminal-Proteus */
	/* Receive data on slave device */
		/*u8 received_data = SPI_SlaveReceive();*/
	/* print received data on LCD */
		/*LCD_voidWriteData(received_data);*/
	
	/* USART: receive character from virtual terminal-Proteus */
		/*u8 data = USART_receiveChar();
		LCD_voidWriteData(data);*/
	/* USASRT: send char from keypad to terminal */
		/*while(KP_getChar()==NOT_PRESSED);
		u8 kp_data =KP_getChar();
		USART_sendChar(kp_data);*/
		
	/* fast PWM testing with buzzer on KP (FAST_PWM mode) */
		/*Timer0_kpBuzzer();*/
		
	/* Timer to toggle LED every second + stop using ext. interrupt on KP (NORMAL mode) */
		/*Timer0_tglLed();*/
	/* external interrupt for counter & external interrupt to stop/start timer (timer LED stops/starts) (NORMAL mode) */	
		/*ExtInt1_kpCntr();*/
		
	/* ADC: LDR and potentiometer */
		/*LDR_read();*/
		
	/* Hamoksha hates the sun */
		/*Hamoksha_hatestheSun();*/
		
	/* Hamoksha goes to sleep */
		/*Hamoksha_sleep();*/
	
	/* ADC: LM */
		/*LM_read();*/
	}
}

