
#ifndef TIMER0_H_
#define TIMER0_H_


static s16 timer0_overflows=0;
//static u8 timer0_isrFlag;

void Timer0_kpBuzzer(){
	/* buzzer enabled in main */
	while(KP_getChar()==NOT_PRESSED){}
		u8 temp=KP_getChar();
	if(temp=='0')
	{
		TIMER0_setDuty(20);
		LCD_voidPrintNum(20);
	}
	else if(temp=='=')
	{
		TIMER0_setDuty(40);
		LCD_voidPrintNum(40);
	}
	else if(temp=='+')
	{
		TIMER0_setDuty(70);
		LCD_voidPrintNum(70);
	}
	else if(temp=='A')
	{
		TIMER0_setDuty(90);
		LCD_voidPrintNum(90);
	}
}

void Timer0_tglLed(){
	/* Timer LED Toggle every 1 second */
	if(timer0_overflows==61){
		
		Dio_voidSetPinValue(PORT_A,PIN4,HIGH);
	}
	else if(timer0_overflows==122){
		timer0_overflows=0;
		Dio_voidSetPinValue(PORT_A,PIN4,LOW);
	}
}


void TIMER0_ISR()
{
	//timer0_isrFlag=1;
	timer0_overflows++;
	
}

#endif