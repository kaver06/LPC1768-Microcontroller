#include<lpc17xx.h>

#define d1 180
#define d2 90
#define d3 360
#define d4 45

void delay(unsigned int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	for(j=0;j<1275;j++);


}
int main()
{
	unsigned int s1 = 200*d1/360;
	unsigned int s2 = 200*d2/360;
	unsigned int s3 = 220*d3/360;
	unsigned int s4 = 230*d4/360;

	unsigned int i =0;
	
	unsigned int clock[]=
				{0x00008000,0x00010000,0x00020000,0x00040000};
	unsigned int anticlock[]=
				{0x00040000,0x00020000,0x00010000,0x00008000};
	
				
	LPC_GPIO0->FIODIR|=0X00078000;

	
		for(i=0;i<s1;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET =clock[i%4];
			delay(200);
		}
		delay(1000);
		for(i=0;i<s2;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET =anticlock[i%4];
			delay(200);
		}		delay(1000);

		for(i=0;i<s3;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET =clock[i%4];
			delay(200);
		}		delay(1000);

		
		for(i=0;i<s4;i++)
		{
			LPC_GPIO0->FIOCLR |=0x00078000;
			LPC_GPIO0->FIOSET =anticlock[i%4];
			delay(200);
		}
	
while(1);

}
