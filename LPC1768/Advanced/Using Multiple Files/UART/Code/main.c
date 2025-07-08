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
		if((receivedchar)=='T')
		{
			UARTSendString("VVCE MYSURU\r\n");
		}
	}
}


