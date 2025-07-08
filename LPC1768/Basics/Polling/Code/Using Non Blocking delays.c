#include <lpc17xx.h>
#include <stdbool.h>
#define KEY_PIN 11
#define LED_PIN 19
#define BLINK_LED 26
volatile unsigned int blinkcounter = 0;
volatile unsigned int debouncetimer = 0;
int main (void)
{
	bool swstatus;
	LPC_GPIO2->FIODIR &= ~(1<<KEY_PIN);
	LPC_GPIO1->FIODIR |= (1<<LED_PIN)|(1<<BLINK_LED);
	LPC_PINCON->PINMODE4 &= 0XFF3FFFFF;
	while(1)
	{
		swstatus = (LPC_GPIO2->FIOPIN & (1<<KEY_PIN));
		while (debouncetimer>500000);
		swstatus = (LPC_GPIO2->FIOPIN & (1<<KEY_PIN));
		if (swstatus == 0)
			LPC_GPIO1->FIOSET = (1<<LED_PIN);
		else
			LPC_GPIO1->FIOCLR = (1<<LED_PIN);
		blinkcounter++;
		if (blinkcounter >= 1000000)
		{
			LPC_GPIO1->FIOPIN ^= (1<<BLINK_LED);
			blinkcounter = 0;
		}
	}
}