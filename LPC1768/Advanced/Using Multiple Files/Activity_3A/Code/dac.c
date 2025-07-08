#include <lpc17xx.h> 
#include "extern.h" 
#include<math.h> 

#define pi 3.14359265
#define samples 1024


int vad=1;
int dac(void) 
{ 
	short int i=0;
	unsigned long int dacrValue = 0;  
	float angle =0;
	SystemInit(); 

	LPC_PINCON->PINSEL1 |= (1 << 21);  
	LPC_PINCON->PINSEL1 &= ~(1 << 20);
	 

	 LPC_DAC->DACR |= (1 << 16); 
	   
	 
	 while(vad<100) 
	 { 
		 for(i=0;i<samples;i++)
		 {
			 angle=(2*pi*i)/samples;
			 dacrValue=(unsigned long int)((sin(angle)+1)*511.5);
		  LPC_DAC->DACR = (dacrValue<< 6);     
		 }	 
		 vad++;
 } 
	 vad=1;
} 
 