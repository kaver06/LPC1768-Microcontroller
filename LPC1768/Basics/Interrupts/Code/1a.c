#include <lpc17xx.h>
#define LED1 19
#define LED2 20
#define BLINKLED 26
#define EX_INT1 1
#define EX_INT2 2
#define KEY_PIN1 11
#define KEY_PIN2 12

void led_init(void);
void interrupt_init(void);
void EINT1_IRQHandler(void);
void EINT2_IRQHandler(void);


int main()
{
	volatile unsigned int blinkcounter = 0;
	led_init();
	interrupt_init();
	while (1)
	{
		if (LPC_GPIO2->FIOPIN & (1<<KEY_PIN1))
			LPC_GPIO1->FIOCLR = (1<<LED1);
		
		if (LPC_GPIO2->FIOPIN & (1<<KEY_PIN2))
			LPC_GPIO1->FIOCLR = (1<<LED2);
		blinkcounter++;
		if (blinkcounter >= 1000000)
		{
			LPC_GPIO1->FIOPIN ^= (1 << BLINKLED);
			blinkcounter = 0;
		}
	}
}
void led_init(void)
{
	LPC_GPIO1->FIODIR |= (1<<LED1)|(1<<LED2)|(1 << BLINKLED);
	LPC_GPIO2->FIODIR &= ~(1<<KEY_PIN1);
	LPC_GPIO2->FIODIR &=~(1<<KEY_PIN2);

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
	LPC_GPIO1->FIOSET =(1<<LED1);
}
void EINT2_IRQHandler(void)
{
	LPC_SC->EXTINT =(1<<EX_INT2);
	LPC_GPIO1->FIOSET =(1<<LED2);
}