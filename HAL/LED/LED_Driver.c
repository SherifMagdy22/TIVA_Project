#include "LED_Driver.h"
uint8 t_on=1;
uint8 t_off=1;
uint8 prev1=LOW;
uint8 prev2=LOW;

void change_blink_rate(void){
		if((GET_BIT(GPIODATAB,0)==HIGH) && prev1 == LOW){
			t_on++;
			t_off--;
			if(t_off<1) t_off=1;
			prev1 = HIGH;
		}
		else if((GET_BIT(GPIODATAB,0)==LOW) && prev1 == HIGH){
			prev1 = LOW;
		}
		
		if((GET_BIT(GPIODATAB,4)==HIGH) && prev2 == LOW){
			t_on--;
			t_off++;
			if(t_on<1) t_on=1;
			prev2 = HIGH;
		}
		else if((GET_BIT(GPIODATAB,4)==LOW) && prev2 == HIGH){
			prev2 = LOW;
		}
}
