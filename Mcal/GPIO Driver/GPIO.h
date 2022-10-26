#include"Mcu_Hw.h"

typedef enum{
	PORTA=0,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF
}Port;

void GPIO_Pin_Init(Port port, uint8 pinNum, uint32 Dir);
