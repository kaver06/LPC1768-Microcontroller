#include<lpc17xx.h>

void delay( unsigned int count)
{
	unsigned int i,j;
	for(i=0;i<count;i++)
	for (j=0;j<1275;j++);
}

int main()
{
	LPC_GPIO1->FIODIR |= 0x07F80000;

	while(1)
	{
		
		LPC_GPIO1->FIOSET |= (1<<19) | (1<<20) | (1<<21) |(1<<22) ;
		delay(2000);
		LPC_GPIO1->FIOCLR |= (1<<19) | (1<<20) | (1<<21) |(1<<22) ;
		delay(2000);
	}
}


		