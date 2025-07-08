#include<LPC17xx.h>
#include "extern.h"

int main(void)
{
	SystemInit();
	
	UARTInitialize();
	while(1)
	{
		char receivedchar;
		receivedchar=UARTReceiveCharacter();
		if((receivedchar)=='V' | (receivedchar)=='v')
		{
			UARTSendString("VVCE Mysuru\r\n");
		}
		else if((receivedchar)=='N' | (receivedchar)=='n')
		{
			UARTSendString("NIE Mysuru\r\n");
		}
		else if((receivedchar)=='S' | (receivedchar)=='s')
		{
			UARTSendString("SJCE Mysuru\r\n");
		}
		else if((receivedchar)=='G' | (receivedchar)=='g')
		{
			UARTSendString("GSSS Mysuru\r\n");
		}
		else
			UARTSendString("Error\r\n");
	}
}


