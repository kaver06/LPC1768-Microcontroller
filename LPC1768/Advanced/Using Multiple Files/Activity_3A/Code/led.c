#include<lpc17xx.h>
#include "extern.h"
int vall=0;

int led(void)
{
	LPC_GPIO1->FIODIR |= 0x07F80000;
	
	while(vall<4)
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
	
		vall++;
	}
	vall=1;
	LPC_GPIO1->FIOCLR |= 0x07F80000;

}

		