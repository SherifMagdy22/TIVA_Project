#include "Timer.h"
#include "Timer_Cfg.h"

void Timer_Init(uint32 ticks){
	STRELOAD &= 0xFF000000;
	STRELOAD |= ticks;
	if(CLCK_SRC==0) STCTRL |= 0x00000001;
	else if(CLCK_SRC==1) STCTRL |= 0x00000005;
}

