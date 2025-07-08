#include<lpc17xx.h>

int main()
{
	LPC_GPIO0->FIODIR |= 0x000001F7;
	
	LPC_GPIO4->FIODIR |= (1<<28);
	
	LPC_GPIO0->FIOPIN=0x00000040;
	
	LPC_GPIO0->FIOSET|=(1<<2);
	LPC_GPIO4->FIOSET|=(1<<28);
	
	while(1);

}
