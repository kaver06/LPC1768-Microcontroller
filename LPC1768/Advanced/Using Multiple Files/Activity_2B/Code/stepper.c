#include<lpc17xx.h>
#include "extern.h"


int stepper(int degrees, int val)
{
	unsigned int steps = 200*degrees/360;
	unsigned int i =0;
	
	unsigned int clock[]=
				{0x00008000,0x00010000,0x00020000,0x00040000};
	unsigned int anticlock[]={0x00040000,0x00020000,0x00010000,0x00008000};
	
				
	LPC_GPIO0->FIODIR|=0X00078000;

	if(val==0)
	{
		for(i=0;i<steps;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET =clock[i%4];
			delay(200);
		}
	}
	if(val==1)
	{
		for(i=0;i<steps;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET =anticlock[i%4];
			delay(200);
		}
	}
	return 0;
}