
#ifndef MCU_HW_H_
#define MCU_HW_H_

#include "Common_Types.h"
#include "BitMath.h"

typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :8;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;

/*
typedef struct 
{
    uint32 MEMA     :1;
    uint32 BUSA     :1;
    uint32          :1;
    uint32 USGA     :1;
    uint32          :3;
    uint32 SVCA     :1;
    uint32 MON      :1;
    uint32          :1;
    uint32 PNDSV    :1;
    uint32 TICK     :1;
    uint32 USAGEP   :1;
    uint32 MEMP     :1;
    uint32 BUSP     :1;
    uint32 SVC      :1; 
		uint32 MEM      :1;
		uint32 BUS      :1;
		uint32 USAGE    :1;
  	uint32          :13;
}SYSHNDCTRL_BF;
typedef union 
{
    uint32 R;
    SYSHNDCTRL_BF B;
}SYSHNDCTRL_Tag;
*/


#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *(volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04)
#define EN0                                    *(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x100)
#define SYSHNDCTRL                             *(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD24)
#define STCTRL                                 *(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x010)
#define STRELOAD                               *(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x014)
#define STCURRENT                              *(volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0x018)	

#define GPIO_PERI_BASE_ADDRESS                 0x40004000
#define GPIOIMA                                *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x410)
#define GPIOISA                                *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x404)
#define GPIODATA                               *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x3FC)
#define GPIOIEVA 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x40C)
#define GPIOAMSEL 														 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x528)
#define GPIODIRA                               *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x400)
#define GPIODENA 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x51C)
#define GPIODIRB 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x1400)
#define GPIODENB 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x151C)
#define GPIODIRC 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x2400)
#define GPIODENC 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x251C)
#define GPIODIRD															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x3400)
#define GPIODEND 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x351C)
#define GPIODIRE															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x20400)
#define GPIODENE 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x2051C)
#define GPIODIRF															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x21400)
#define GPIODENF 															 *(volatile uint32*)(GPIO_PERI_BASE_ADDRESS+0x2151C)

#define RCGCGPIO 															 *(volatile uint32*)(0x400FE000+0x608)



#endif
