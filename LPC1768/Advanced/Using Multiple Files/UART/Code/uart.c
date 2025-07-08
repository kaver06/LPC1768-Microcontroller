#include<LPC17xx.h>

void UARTInitialize(void)
{
	LPC_PINCON->PINSEL0 &=~((3<<4) |(3<<6));
	LPC_PINCON->PINSEL0 |=((1<<4) |(1<<6));
	
	LPC_UART0->FCR=(1<<0)|(1<<1)|(1<<2);
	
	LPC_UART0->LCR=(1<<0)|(1<<1)|(1<<7);
	
	LPC_SC->PCLKSEL0 &= ~((1<<6)|(1<<7));
	
	LPC_UART0->DLL=0XA2;
	LPC_UART0->DLM=0X00;

	LPC_UART0->LCR &=~(1<<7);
}

void UARTSendCharacter(char ch)
{
	while((LPC_UART0->LSR & (1<<5))==0);
	LPC_UART0->THR=ch;
}
void UARTSendString(char *str)
{
	if(str=='\0')return;
	while(*str)
	{
		UARTSendCharacter(*str++);
	}
}
char UARTReceiveCharacter(void)
{
	while ((LPC_UART0->LSR&(1<<0))==0);
		return LPC_UART0->RBR;
}
