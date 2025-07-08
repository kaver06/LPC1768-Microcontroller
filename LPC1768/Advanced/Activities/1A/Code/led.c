#include<lpc17xx.h>

void delay(unsigned int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	for(j=0;j<1275;j++);
}

int main()
{
	LPC_GPIO1->FIODIR |= 0x07F80000;
	while(1)
	{
		LPC_GPIO1->FIOCLR |= (1<<19) | (1<<26);
		LPC_GPIO1->FIOSET |= (1<<22) | (1<<23);
		delay(4000);
		LPC_GPIO1->FIOCLR |= (1<<22) | (1<<23);
		LPC_GPIO1->FIOSET |= (1<<21) | (1<<24);
		delay(4000);
		LPC_GPIO1->FIOCLR |= (1<<21) | (1<<24);
		LPC_GPIO1->FIOSET |= (1<<20) | (1<<25);
		delay(4000);
		LPC_GPIO1->FIOCLR |= (1<<20) | (1<<25);
		LPC_GPIO1->FIOSET |= (1<<19) | (1<<26);
		delay(4000);
	
		
	}
}

		