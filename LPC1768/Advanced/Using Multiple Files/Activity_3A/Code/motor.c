
#include <lpc17xx.h>
#include "extern.h"
int motor(void) {
    int i;
    LPC_GPIO2->FIODIR |= (1 << 2);  
    for (i = 0; i < 50; i++) {
        LPC_GPIO2->FIOSET = (1 << 2);
        delay(2000);
        LPC_GPIO2->FIOCLR = (1 << 2); 
        delay(1000);
    }
    LPC_GPIO2->FIOCLR = (1 << 2);   
    delay(2000);
}
