#ifndef ICU_H_
#define ICU_H_

static u16 period;
/*static u16 T_on;*/
static u16 T_on;



void ICU()
{
	/* b3 to d2 */
	Dio_voidSetPinValue(PORT_A,PIN4,HIGH);
	
	/* wait for interrupt 1 */
	while(1)
	{
		if(exti1_counter==1)
		{
			/* reset timer*/
			Timer1_Reset();
			/* read Timer1 counter value (TCNT1L,H) */
			//period=Timer1_u16GetCounterValue();
			break;
		}
	}
	/* wait for interrupt 2 to calc "period" */
	while(1)
	{
		if(exti1_counter==2)
		{
			/* read Timer1 counter value (TCNT1L,H) */
			period=Timer1_u16GetCounterValue();//-period;
			/* switch interrupt 1 sens mode*/
			EXTI1_sensMode(I1_LOW);
			/* reset timer*/
			break;
		}
	}
	/* waiting for interrupt 3 to calculate T_on */
	while(1)
	{	
		if(exti1_counter==3)
		{
			T_on=Timer1_u16GetCounterValue()-period;
			break;
		}
	}
	Dio_voidSetPinValue(PORT_A,PIN4,LOW);
	LCD_voidPrintStr("Period = ");
	LCD_voidPrintNum(period);
	LCD_goto(1,0);
	LCD_voidPrintStr("T_on = ");
	LCD_voidPrintNum(T_on);
}



#endif /* ICU_H_ */