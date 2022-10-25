#include "IntCtrl.h"
#include "IntCtrl_Types.h"

extern uint8 Enabled_Interrupts[];

static void(*func_ptr)(void)=0;

void SysTick_Handler(){
	func_ptr();
}

void SysTick_Save_Callback(void(*callback_ptr)(void)){
	func_ptr = callback_ptr;
}

void IntCrtl_Init(void)
{

	/*TODO Configure Grouping\SubGrouping System in APINT register in SCB*/
    APINT = 0xFA05|0x00001234;
    
    /*TODO : Assign Group\Subgroup priority in NVIC_PRIx Nvic and SCB_SYSPRIx Registers*/  


	/*TODO : Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */
	uint32 temp1=0;
	uint32 temp2=0;
	uint8 i;
	for(i=0;i<N;i++){
		if(Enabled_Interrupts[i] == MEMORY_MANAGEMENT)temp1 |= 0x00010000;
		else if(Enabled_Interrupts[i] == BUS_FAULT) temp1 |= 0x00020000;
		else if(Enabled_Interrupts[i] == USAGE_FAULT) temp1 |= 0x00040000;	
		else if(Enabled_Interrupts[i] == SYSTICK) STCTRL |= 0x00000002;
  	else if(Enabled_Interrupts[i]>=16){
			temp2 |= 1<<(Enabled_Interrupts[i]-16);
		}
	}
	SYSHNDCTRL |= temp1;
	EN0 |= temp2;

}

