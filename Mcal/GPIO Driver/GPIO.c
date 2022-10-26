#include"GPIO.h"

void GPIO_Pin_Init(Port port, uint8 pinNum, uint32 Dir){
	switch(port){
		case PORTA:
			GPIODIRA |= Dir<<pinNum;
			SET_BIT(GPIODENA, pinNum);
			break;
		case PORTB:
			GPIODIRB |= Dir<<pinNum;
			SET_BIT(GPIODENB, pinNum);
			break;
		case PORTC:
			GPIODIRC |= Dir<<pinNum;
			SET_BIT(GPIODENC, pinNum);
			break;
		case PORTD:
			GPIODIRD |= Dir<<pinNum;
			SET_BIT(GPIODEND, pinNum);
			break;
		case PORTE:
			GPIODIRE |= Dir<<pinNum;
			SET_BIT(GPIODENE, pinNum);
			break;
		case PORTF:
			GPIODIRF |= Dir<<pinNum;
			SET_BIT(GPIODENF, pinNum);
			break;
		default:
			break;
	}
	
}