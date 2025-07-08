#include <LPC17xx.h>

void setrowtozero(unsigned char);
unsigned char readcolumnnumber(void);


char keycodes[4][4]=
{
	{'1','2','3','4'},
	{'5','6','7','8'},
	{'9','0','A','B'},
	{'C','D','E','F'}
};	

void keypadinitialize(void)
{
	LPC_GPIO1->FIODIR|=(1<<9)|(1<<10)|(1<<14)|(1<<15);
	LPC_GPIO1->FIODIR &= ~((1<<0)|(1<<1)|(1<<4)|(1<<8));
}

void setrowtozero(unsigned char rownumber)
{
	LPC_GPIO1->FIOSET |=(1<<9)|(1<<10)|(1<<14)|(1<<15);
	switch(rownumber)
	{
		case 0: LPC_GPIO1->FIOCLR|=(1<<9);
				break;
		case 1: LPC_GPIO1->FIOCLR|=(1<<10);
				break;
		case 2: LPC_GPIO1->FIOCLR|=(1<<14);
				break;
		case 3: LPC_GPIO1->FIOCLR|=(1<<15);
				break;
	}
}

unsigned char readcolumnnumber(void)
{
	unsigned long int temp =LPC_GPIO1->FIOPIN;
	
	if((temp &(1<<0))==0)
		return 0;
	else if((temp & (1<<1))==0)
		return 1;
	else if((temp & (1<<4))==0)
		return 2;
	else if((temp & (1<<8))==0)
		return 3;
	else
		return 4;
}

unsigned char getkeypressed(void)
{
	unsigned char rownumber,colnumber;
	while(1)
	{
		for(rownumber=0;rownumber <4;rownumber++)
		{
			setrowtozero(rownumber);
			colnumber=readcolumnnumber();
			
			if(colnumber<4)
				return keycodes[rownumber][colnumber];
		}
	}
}

void delay(int ms)
{
	unsigned int i,j;
	for(i=0;i<ms;i++)
	for(j=0;j<1275;j++);
}
