
#ifndef ADC_H_
#define ADC_H_

static u8 adc_flag=0;
static u16 LDR_reading=0;
static u16 LM_reading=0;


void LDR_read()
{	
	/*(5000UL* (u16) ADC_read(ADC0))/1024;*/ /*((u16) (5000UL* ADC_read(ADC0)))/1024*/	/* casting because number is too big */
	LDR_reading=(5000UL* (u16) ADC_read(ADC0))/1024;
/* ADC polling LDR*/
	/*LCD_goto(1,1);*/
	/*LCD_voidCls();
	LCD_voidPrintNum(LDR_reading);
	_delay_ms(200);*/
/* LDR (using ADC interrupt) testing */
	if(adc_flag==1)
	{	
		LCD_voidCls();
		LCD_goto(1,1);
		LCD_voidPrintNum(LDR_reading);
		_delay_ms(200);
		adc_flag=0;
	}
}

void LM_read(){
	LM_reading=(500UL* (u16) ADC_read(ADC1))/1024;
	if(adc_flag==1)
	{
		//LCD_voidCls();
		LCD_goto(1,1);
		LCD_voidPrintNum(LM_reading);
		LCD_voidPrintStr(" de. Cel.");
		adc_flag=0;
	}
}

void ADC_flag()
{
	adc_flag=1;
}

#endif /* ADC_H_ */