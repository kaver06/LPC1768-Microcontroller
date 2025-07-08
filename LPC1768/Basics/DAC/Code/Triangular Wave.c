#include <lpc17xx.h> 

void delay(unsigned int ms) 
{ 
	unsigned int i,j;  
	for(i=0; i<ms; i++) 
	for(j=0; j<1275; j++); 
} 
int main(void) 
{ 
	short int i=0;
	unsigned long int dacrValue = 0;  
	SystemInit(); 

	LPC_PINCON->PINSEL1 |= (1 << 21);  
	LPC_PINCON->PINSEL1 &= ~(1 << 20);
	 

	 LPC_DAC->DACR |= (1 << 16); 
	   
	 
	 while(1) 
	 { 
		 for(i=0;i<1024;i++)
		 {
		  dacrValue &= ~(0x3FF << 6);  
		  dacrValue |= (i << 6);  
		  LPC_DAC->DACR = dacrValue;     
		 }	 
		 for(i=1023;i<0;i--)
		 {
			 dacrValue &= ~(0x3FF << 6);  
		  dacrValue |= (i << 6);  
		  LPC_DAC->DACR = dacrValue;  
		 }
 } 
} 
 