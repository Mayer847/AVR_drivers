
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "Dio_interface.h"
#include "Dio_private.h"


void Dio_voidSetPinDirection(u8 PORTID, u8 PINID, u8 Direction){
	if((PORTID< 4) && (PINID<8) ){
		if(Direction == OUTPUT){
			switch(PORTID)
			{
				case PORT_A : SET_BIT(DDRA_REG,PINID); break;
				case PORT_B : SET_BIT(DDRB_REG,PINID); break;
				case PORT_C : SET_BIT(DDRC_REG,PINID); break;
				case PORT_D : SET_BIT(DDRD_REG,PINID); break;
			}
		}
		else if(Direction == INPUT){
			switch(PORTID)
			{
				case PORT_A : CLR_BIT(DDRA_REG,PINID); break;
				case PORT_B : CLR_BIT(DDRB_REG,PINID); break;
				case PORT_C : CLR_BIT(DDRC_REG,PINID); break;
				case PORT_D : CLR_BIT(DDRD_REG,PINID); break;
			}
		}else{/* Direction Error */}
	}else{/* Error Out of Range */}
}

void Dio_voidSetPinValue(u8 PORTID, u8 PINID, u8 Value){
	if((PORTID< 4) && (PINID<8) ){
		if(Value==HIGH){
			switch(PORTID)
			{
				case PORT_A : SET_BIT(PORTA_REG,PINID);break;
				case PORT_B : SET_BIT(PORTB_REG,PINID);break;
				case PORT_C : SET_BIT(PORTC_REG,PINID);break;
				case PORT_D : SET_BIT(PORTD_REG,PINID);break;
			}
		}else if(Value==LOW){
			switch(PORTID)
			{
				case PORT_A : CLR_BIT(PORTA_REG,PINID);break;
				case PORT_B : CLR_BIT(PORTB_REG,PINID);break;
				case PORT_C : CLR_BIT(PORTC_REG,PINID);break;
				case PORT_D : CLR_BIT(PORTD_REG,PINID);break;
			}
		}
	}else{/* Error out of range */}
}

u8 Dio_u8GetPinValue(u8 PORTID, u8 PINID){
	//u8 Local_PinVal ;
	
	if((PORTID< 4) && (PINID<8) ){
		switch(PORTID)
		{
			case PORT_A : return GET_BIT(PINA_REG,PINID);
			case PORT_B : return GET_BIT(PINB_REG,PINID);
			case PORT_C : return GET_BIT(PINC_REG,PINID);
			case PORT_D : return GET_BIT(PIND_REG,PINID);
		}
	}else{/* Error out of range */ }
	return 0x55;
}

void Dio_voidTogglePin(u8 PORTID, u8 PINID){
	if((PORTID< 4) && (PINID<8)){
		switch(PORTID)
		{
			case PORT_A : TOG_BIT(PORTA_REG,PINID); break;
			case PORT_B : TOG_BIT(PORTB_REG,PINID); break;
			case PORT_C : TOG_BIT(PORTC_REG,PINID); break;
			case PORT_D : TOG_BIT(PORTD_REG ,PINID); break;
		}
	}else{/* Error out of range */}
}

void Dio_voidSetPortValue(u8 PORTID, u8 Value){
	if(PORTID< 4){ //&& (Value<255)
		switch(PORTID)
		{
			case PORT_A :PORTA_REG=Value; break;
			case PORT_B :PORTB_REG=Value; break;
			case PORT_C :PORTC_REG=Value; break;
			case PORT_D :PORTD_REG=Value; break;
		}
	}else{/* Error out of range */}
}

void Dio_voidSetPortDirection(u8 PORTID, u8  Direction){
	if((PORTID< 4) && (Direction==1 || Direction==0) ){
		if(Direction==1){
			switch(PORTID)
			{
				case PORT_A :PORTA_REG=0xff; break;
				case PORT_B :PORTB_REG=0xff; break;
				case PORT_C :PORTC_REG=0xff; break;
				case PORT_D :PORTD_REG=0xff; break;
			}
		}else if(Direction==0){
			switch(PORTID)
			{
				case PORT_A :PORTA_REG=0; break;
				case PORT_B :PORTB_REG=0; break;
				case PORT_C :PORTC_REG=0; break;
				case PORT_D :PORTD_REG=0; break;
			}
		}else{/* Wrong Direction */}
	}else{/* Error out of range */}
}


/*include std_types

u8 DIO_u78GetPinValue(u8 Port,u8 Pin)
u8 Local_u8Val =0x55; //55 to differentiate between it and initial value or stored value
*/