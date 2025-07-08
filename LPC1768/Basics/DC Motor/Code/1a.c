#include<lpc17xx.h>

#define PWM_PIN 2
#define DUTYCYCLE 20
#define Period 100

int main(void)
{
	unsigned int i;
	
	unsigned int on_time;
	unsigned int off_time;
	
	LPC_GPIO2->FIODIR|=(1<<PWM_PIN);
	
	on_time=(Period*DUTYCYCLE)/100;
	off_time=Period-on_time;
	
	while(1)
	{
		LPC_GPIO2->FIOSET=(1<<PWM_PIN);
		for(i=0;i<on_time;i++);
		
		LPC_GPIO2->FIOCLR=(1<<PWM_PIN);
		for(i=0;i<off_time;i++);
	}
}