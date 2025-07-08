#include<lpc17xx.h>
#include "extern.h" 
#define degrees 360
int va=1;
int stepp_cc(void)
{
	unsigned int steps = 200*degrees/360;
	unsigned int i =0;
	

	unsigned int anticlock[]=
				{0x00040000,0x00020000,0x00010000,0x00008000};
	
				
	LPC_GPIO0->FIODIR|=0X00078000;

	while(va<2)
	{
		for(i=0;i<steps;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET =anticlock[i%4];
			delay(200);
		}
		va++;
	}
	va=1;

}
