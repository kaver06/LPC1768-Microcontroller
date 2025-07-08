#include <lpc17xx.h>
#define LED1 19
#define LED2 20
#define BLINKLED 26
#define EX_INT1 1
#define EX_INT2 2
#define KEY_PIN1 11
#define KEY_PIN2 12

int i;

void led_init(void);
void interrupt_init(void);
void EINT1_IRQHandler(void);
void EINT2_IRQHandler(void);
void delay(unsigned ms)
{
	unsigned int j,p;
	for(p=0;p<ms;p++)
		for(j=0;j<1275;j++);
}


int main()
{
	volatile unsigned int blinkcounter = 0;
	led_init();
	interrupt_init();
	while (1)
	{
		/*if (LPC_GPIO2->FIOPIN & (1<<KEY_PIN1))
			LPC_GPIO1->FIOCLR = (1<<LED1);
		
		if (LPC_GPIO2->FIOPIN & (1<<KEY_PIN2))
			LPC_GPIO1->FIOCLR = (1<<LED2);
		blinkcounter++;
		if (blinkcounter >= 1000000)
		{
			LPC_GPIO1->FIOPIN ^= (1 << BLINKLED);
			blinkcounter = 0;
		}*/
	}
}
void led_init(void)
{
	LPC_GPIO1->FIODIR |= (1<<LED1)|(1<<LED2)|(1 << BLINKLED);
	LPC_GPIO2->FIODIR &= ~(1<<KEY_PIN1);
	LPC_GPIO2->FIODIR &=~(1<<KEY_PIN2);
	LPC_GPIO1->FIODIR |= 0x07F80000;

}
void interrupt_init(void)
{
	LPC_SC->EXTINT =(1<<EX_INT1);
	LPC_SC->EXTINT =(1<<EX_INT2);

	LPC_PINCON->PINSEL4 |= (1 << 22);
	LPC_PINCON->PINSEL4 &= ~(1 << 23);
	
	LPC_PINCON->PINSEL4 |= (1 << 24);
	LPC_PINCON->PINSEL4 &= ~(1 << 25);
	
	LPC_SC->EXTMODE |=(1<<EX_INT1);
	LPC_SC->EXTMODE |=(1<<EX_INT2);

	LPC_SC->EXTPOLAR &= ~(1<<EX_INT1);
	LPC_SC->EXTPOLAR &= ~(1<<EX_INT2);

	NVIC_EnableIRQ(EINT1_IRQn);
	NVIC_EnableIRQ(EINT2_IRQn);
}
void EINT1_IRQHandler(void)
{
	LPC_SC->EXTINT =(1<<EX_INT1);
	for(i=19;i<27;i++)
	{
		LPC_GPIO1->FIOSET =(1<<i);
		LPC_GPIO1->FIOCLR = (1<<(i-1));
		delay(1000);
	}
	LPC_GPIO1->FIOCLR = (1<<26);
}
void EINT2_IRQHandler(void)
{
	LPC_SC->EXTINT =(1<<EX_INT2);
	for(i=0;i<27;i++)
	{
		LPC_GPIO1->FIOSET =(1<<i);
		delay(1000);
	}
	for(i=0;i<27;i++)
	{
		LPC_GPIO1->FIOCLR =(1<<i);
		delay(1000);
	}
}


	