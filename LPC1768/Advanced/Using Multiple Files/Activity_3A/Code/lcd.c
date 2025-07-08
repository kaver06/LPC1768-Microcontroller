#include<LPC17xx.h>
#include "extern.h"

#define RS 9
#define RW 10
#define E  11




void lcdinit(void)
{
	LPC_GPIO0->FIODIR|=(1<<22)|(1<<21)|(1<<20)|(1<<19);
	
	LPC_GPIO0->FIODIR|=(1<<11)|(1<<10)|(1<<9);
	
	lcdchar(0x33,'C');
	delay(100);
	
	lcdchar(0x32,'C');
	delay(100);
	
	lcdchar(0x28,'C');
	delay(100);
	
	lcdchar(0x0C,'C');
	delay(100);
	
	lcdchar(0x06,'C');
	delay(100);
	
	lcdchar(0x01,'C');
	delay(100);
	
	lcdstring("Welcome");
	delay(15000);
	lcdchar(0xc0,'C');
	lcdstring("Loading");
	delay(4500);
	lcdstring(".");
	delay(4500);
	lcdstring(".");
	delay(4500);
	lcdstring(".");
	delay(8500);
	lcdchar(0x01,'C');
	lcdstring("Press a Key");
}

void lcdstring(char *str)
{
	unsigned char i=0;
	while(str[i]!='\0')
	{
		lcdchar(str[i],'D');
		i++;
	}
}

void lcdchar(unsigned char data,unsigned char type)
{
	unsigned char lowernibble=data&0x0F;
	
	unsigned char uppernibble=(data&0xF0)>>4;
	
	if(type=='C')
		LPC_GPIO0->FIOCLR=(1<<RS);
	else if(type=='D')
		LPC_GPIO0->FIOSET=(1<<RS);
	
	LPC_GPIO0->FIOSET|=(1<<E);
	LPC_GPIO0->FIOCLR|=(0x0F<<19);
	LPC_GPIO0->FIOSET|=(uppernibble<<19);
	LPC_GPIO0->FIOCLR|=(1<<E);
	delay(100);
	
	LPC_GPIO0->FIOSET|=(1<<E);
	LPC_GPIO0->FIOCLR|=(0x0F<<19);
	LPC_GPIO0->FIOSET|=(lowernibble<<19);
	LPC_GPIO0->FIOCLR|=(1<<E);
	delay(100);
}
