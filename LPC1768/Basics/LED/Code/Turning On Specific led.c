#include<lpc17xx.h>

int main()
{
	LPC_GPIO1-> FIODIR|=(1<<19) | (1<<21) | (1<<23) | (1<<25);
	LPC_GPIO1-> FIOSET|=(1<<19) | (1<<21) | (1<<23) | (1<<25);
	
	while(1);
}
