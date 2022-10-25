#ifndef INTCTRL_H_
#define INTCTRL_H_
#include "Mcu_Hw.h"
#include "IntCtrl_Cfg.h"

void IntCrtl_Init(void);
void SysTick_Save_Callback(void(*callback_ptr)(void));

#endif
