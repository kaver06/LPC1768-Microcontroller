#include<lpc17xx.h>
int main()
{
	LPC_GPIO1->FIODIR=0x01000000;
	
	LPC_GPIO1->FIOSET=0x01000000;
	while(1);
}