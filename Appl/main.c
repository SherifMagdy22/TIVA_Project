#include "Timer.h"
#include "IntCtrl.h"
#include "LED_Driver.h"

static uint32 OverflowCount=0;
static uint32 remainder1=0;
static uint32 counts1=0;
static uint32 remainder2=0;
static uint32 counts2=0;
uint8 toggle=0;
uint8 rem_done=0;
extern uint8 t_on;
extern uint8 t_off;

/*
void GPIOB_ISR_func(void){
	SET_BIT(GPIODATA,1);
}
	GPIOB_Save_Callback(&GPIOB_ISR_func);
	GPIOISB &= 0x00000001;
	GPIOIBEB &= 0x0000000;
	GPIOIEVB |= 0x00000000;
	GPIOIMB |= 0x0000000F;
*/

void SysTick_ISR_func(void){
	if(toggle==0){
		SET_BIT(GPIODATA,0);
		STRELOAD &= 0xFF000000;
		
		if(OverflowCount>=counts1){
			rem_done=0;
			toggle=1;
			OverflowCount=0;
		}
		if(rem_done==1){
			STRELOAD |= 0x00FFFFFF;
			OverflowCount++;
		}
		else if(rem_done==0){
			STRELOAD |= remainder1;
			rem_done=1;
		}
	}
	else if(toggle==1){
		CLEAR_BIT(GPIODATA,0);
		STRELOAD &= 0xFF000000;
		
		if(OverflowCount>counts2){
			rem_done=0;
			toggle=0;
			OverflowCount=0;
		}
		if(rem_done==1){
			STRELOAD |= 0x00FFFFFF;
			OverflowCount++;
		}
		else if(rem_done==0){
			STRELOAD |= remainder2;
			rem_done=1;
		}
	}
}

void time_select(uint8 t1, uint8 t2){
	float32 time_per_count = ((float32)(16777215)/(Clock_freq));
	counts1 = t1/time_per_count;
	remainder1 = (((t1 - time_per_count*counts1))*((16777215)));
	counts2 = t2/time_per_count;
	remainder2 = (((t2 - time_per_count*counts2))*((16777215)));
}

int main(void){
	
	GPIO_Pin_Init(PORTA,0,OUTPUT);
	GPIO_Pin_Init(PORTB,0,INPUT);
	GPIO_Pin_Init(PORTB,4,INPUT);

	SET_BIT(GPIODATA,0);
	SysTick_Save_Callback(&SysTick_ISR_func);
	IntCrtl_Init();
	while(1){
		change_blink_rate();
		time_select(t_on, t_off);
		Timer_Load(remainder1);
		rem_done=1;
	}
}

