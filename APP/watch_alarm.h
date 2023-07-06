/*
 * watch_alarm.h
 *
 * Created: 6/22/2023 8:37:14 PM
 *  Author: Mayer
 */ 


#ifndef WATCH_ALARM_H_
#define WATCH_ALARM_H_

void watch_alarm(){
	// Turn off the display
	LCD_voidCommand(0x08);
	while(!exti1_flag);
	LCD_voidCommand(0x0C);/* Turn on the display without clearing it */
	LCD_voidCls();
	while(KP_getChar()==NOT_PRESSED);
	u8 temp = KP_getChar();
	while(temp <= '0' && temp > '9'){
		temp=KP_getChar();
	}
	u8 number= temp-'0';
	timer0_overflows=1;
	LCD_voidPrintNum(number);
	while(number>0){
		
		if(timer0_overflows==61) /* 61 overflow Normal mode */
		//if(timer0_isrFlag) /* timer0 interrupt using compare match 61 with prescalar = 1024 */
		{
			timer0_overflows=0;
			number--;
			//TIMER0_reset();
			LCD_voidPrintNum(number);
			
			//timer0_isrFlag=0;
		}
	}
	/*buzzer*/
	Dio_voidSetPinValue(PORT_C,PIN6,HIGH);	
	LCD_voidPrintStr("TIME IS UP !!!");
	Dio_voidSetPinValue(PORT_C,PIN6,LOW);
	exti1_flag=0;

}


#endif /* WATCH_ALARM_H_ */