
#define HIGH 1
#define LOW 0

#define OUTPUT 1
#define INPUT 0

#define SET_BIT(Reg,Bit_No)     (Reg |= (uint32)(1<<Bit_No))
#define CLEAR_BIT(Reg,Bit_No)   (Reg &= (uint32)~(1<<Bit_No))
#define GET_BIT(Reg,Bit_No)     (Reg & (1<<Bit_No))>>Bit_No
#define TOGGLE_BIT(Reg,Bit_No)  (Reg ^= (uint32)(1<<Bit_No))