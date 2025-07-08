#include <lpc17xx.h>
#define STEPS 10

void delay(unsigned int ms)
{
	unsigned int i,j;
	for(i=0; i<ms; i++)
		for(j=0; j<1275; j++);
}
int main(void)
{
	
	unsigned long int dacrValue = 0;
	unsigned long int step_value= 0;
	unsigned int i;
	SystemInit();
	LPC_PINCON->PINSEL1 |=(1<<21);
	LPC_PINCON->PINSEL1 &=~(1<<20);
	LPC_DAC->DACR |= (1<<16);
	while(1)
	{
		for(i=STEPS; i>0;i--)
		{
			step_value=(1023*i)/(STEPS+1);
			dacrValue &= ~(0x3FF<<6);
			dacrValue |= (step_value<<6);
			LPC_DAC->DACR = dacrValue;
			delay(400);
		}
		for(i=0; i<STEPS;i++)
		{
			step_value=(1023*i)/(STEPS-1);
			dacrValue &= ~(0x3FF<<6);
			dacrValue |= (step_value<<6);
			LPC_DAC->DACR = dacrValue;
			delay(400);
		}
	}
}


























































































































































