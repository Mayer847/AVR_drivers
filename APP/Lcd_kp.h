#ifndef LCD_KP_H_
#define LCD_KP_H_

#include "../HAL/KP/KP_interface.h"


void Lcd_kp_tests(){
/*LCD TESTS & KEY PAD TESTS 	*/

	LCD_voidPrintStr("test123");
	_delay_ms(500);
	LCD_goto(2,8);
	LCD_voidPrintNum(777);
	_delay_ms(500);
	LCD_voidCls();	

	while(1){
		
		while(KP_getChar()==NOT_PRESSED);
		u8 temp=KP_getChar();
		if(temp != NOT_PRESSED)
			LCD_voidWriteData(temp);
		
	}
}

#endif