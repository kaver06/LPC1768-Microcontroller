#include <lpc17xx.h>
#include "extern.h"
int main()
{
	unsigned char key;
	
	keypadinitialize();

	while(1)
	{
		key=getkeypressed();
		delay(20);
		
		switch(key)
		{
			case '0': stepper(45,0);
						break;
			case '1': stepper(90,0);
						break;
			case '2': stepper(135,0);
						break;
			case '3': stepper(180,0);
						break;
			case '4': stepper(225,0);
						break;
			case '5': stepper(270,0);
						break;
			case '6': stepper(315,0);
						break;
			case '7': stepper(360,0);
						break;
			case '8': stepper(45,1);
						break;
			case '9': stepper(90,1);
						break;
			case 'A': stepper(135,1);
						break;
			case 'B': stepper(180,1);
						break;
			case 'C': stepper(225,1);
						break;
			case 'D': stepper(270,1);
						break;
			case 'E': stepper(315,1);
						break;
			case 'F': stepper(360,1);
						break;
		}
	}
}
