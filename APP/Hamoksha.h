/*
 * Hamoksha.h
 *
 * Created: 6/22/2023 6:05:36 PM
 *  Author: Mayer
 */ 


#ifndef HAMOKSHA_H_
#define HAMOKSHA_H_


/*
u8 smiley[8] = {0x00, 0x0A, 0x00, 0x04, 0x00, 0x11, 0x0E, 0x00};
u8 Hamoksha_face[8] = {0b11111, 0b11011, 0b11011,0b10101, 0b11111, 0b00100, 0b01110, 0b10101};*/
static u8 Hamoksha_happy[8]= {0x00,0x00,0x0A,0x00,0x11,0x0E,0x00,0x00};
static u8 Hamoksha_sad[8]={0x00,0x00,0x0A,0x00,0x00,0x0E,0x11,0x00};
static u8 Hamoksha_neutral[8]= {0x00,0x00,0x0A,0x00,0x00,0x1F,0x00,0x00};
static u8 Hamoksha_body[8] ={ 0b01110, 0b10101, 0b10101, 0b00100, 0b01110, 0b01010, 0b01010, 0b01010};
static u8 Hamoksha_bodySl1[8]={0x00,0x00,0x03,0x04,0x08,0x10,0x10,0x00};
static u8 Hamoksha_bodySl2[8]={0x00,0x00,0x1F,0x00,0x00,0x00,0x00,0x00};
static u8 Hamoksha_faceSleeping[8]={0x00,0x02,0x12,0x10,0x10,0x12,0x02,0x00};
static u8 sleeping_z1[8]={0x04,0x08,0x1E,0x00,0x0F,0x02,0x04,0x0F};
static u8 sleeping_z2[8]={0x1E,0x04,0x08,0x1E,0x00,0x0F,0x02,0x04};
	
void Hamoksha_hatestheSun(){
		LDR_reading=(5000UL* (u16) ADC_read(ADC0))/1024;
		LCD_create_char(0, Hamoksha_neutral);
		LCD_goto(0,0);
		LCD_voidWriteData(0);
		LCD_create_char(1,Hamoksha_body);
		LCD_goto(1,0);
		LCD_voidWriteData(1);
		if(adc_flag)
		{
			if(LDR_reading>2500)/* at night Hamoksha is happy */
			{
				LCD_create_char(0, Hamoksha_happy);
				LCD_goto(0,0);
				LCD_voidWriteData(0); // display the custom character
			}
			else if(LDR_reading>0){
				LCD_create_char(0, Hamoksha_sad);
				LCD_goto(0,0);
				LCD_voidWriteData(0); // display the custom character
			}
			adc_flag=0;
		}
}

void Hamoksha_sleep(){
	LDR_reading=(5000UL* (u16) ADC_read(ADC0))/1024;
	LCD_voidCls();
	LCD_create_char(0, Hamoksha_neutral);
	LCD_goto(0,0);
	LCD_voidWriteData(0);
	LCD_create_char(1,Hamoksha_body);
	LCD_goto(1,0);
	LCD_voidWriteData(1);
	if(adc_flag)
	{
		if(LDR_reading<2500)/* Hamoksha is up in the morning */
		{
			
			LCD_create_char(0, Hamoksha_happy);
			LCD_goto(0,0);
			LCD_voidWriteData(0); 
		}
		else { /* Hamoksha sleeps at night */
			LCD_voidCls();
			LCD_create_char(2,Hamoksha_bodySl1);
			LCD_goto(1,0);
			LCD_voidWriteData(2); 
			
			LCD_create_char(3,Hamoksha_bodySl2);
			LCD_goto(1,1);
			LCD_voidWriteData(3); 
			
			LCD_create_char(4,Hamoksha_faceSleeping);
			LCD_goto(1,2);
			LCD_voidWriteData(4);
			
			
			LCD_create_char(5,sleeping_z1);
			LCD_goto(0,2);
			LCD_voidWriteData(5);
			_delay_ms(100);
			LCD_create_char(5,sleeping_z2);
			LCD_goto(0,2);
			LCD_voidWriteData(5);
			_delay_ms(100);
			LCD_create_char(5,sleeping_z1);
			LCD_goto(0,2);
			LCD_voidWriteData(5);
		}
		adc_flag=0;
	}
}

#endif /* HAMOKSHA_H_ */


//LCD_setCursor(0,0);
//LCD_setCursor(1,0);