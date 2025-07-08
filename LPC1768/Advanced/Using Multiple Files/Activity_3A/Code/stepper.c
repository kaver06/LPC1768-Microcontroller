#include<lpc17xx.h>
#include "extern.h"
#define DEGREES 360
int valll=1;
int stepp(void)
{
	unsigned int steps = 200*DEGREES/360;
	unsigned int i =0;
	
	unsigned int clock[]=
				{0x00008000,0x00010000,0x00020000,0x00040000};

	
				
	LPC_GPIO0->FIODIR|=0X00078000;

	while(valll<2)
	{
		for(i=0;i<steps;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET =clock[i%4];
			delay(200);
		}
		valll++;
	}
	valll=1;

}
