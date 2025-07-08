#include <lpc17xx.h>
#include "extern.h"
int main()
{
	unsigned char key;
	
	keypadinitialize();
	lcdinit();
	lcdstring("Key Pressed");
	while(1)
	{
		key=getkeypressed();
		delay(20);
		lcdchar(0x8C,'C');
		lcdchar(key,'D');
		
	}
}
