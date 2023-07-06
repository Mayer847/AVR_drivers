#ifndef EXTINT_H_
#define EXTINT_H_


static u8 exti1_flag;
static u8 temp;
static u8 counter;
static u16 exti1_counter;

/*void EXTI1_reset();*/

void ExtInt1_kpCntr(){
		
/* interrupt 1 counter '+' switch(Row 4, col 4)*/
	if(exti1_flag==1){
		temp=KP_getChar();
		if(temp=='+')
		{
			LCD_voidCls();
			counter++;
			LCD_voidPrintNum(counter);
		}
		else if (temp == '/')	/* start timer with external interrupt one using switch '/'	*/
		{
			TIMER0_start(PRS1024);
				
		}
		else if (temp== '*')
		{
			/*Dio_voidSetPinValue(PORT_A,PIN4,LOW);*/
			TIMER0_stop();
		}
	}
}



void EXTI1_ISR()
{
	exti1_flag=1;
	exti1_counter++;
}

/*
void EXTI1_count()
{
	
}*/

/*
void EXTI1_reset(){
	while(get_KP()==NOT_PRESSED){}
	if(get_KP()=='-')
	{
		counter=0;
	}
	LCD_voidCls();
	LCD_voidPrintNum(counter);
}*/


#endif