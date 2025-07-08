#ifndef _EXTERN_H
#define __EXTERN_H

extern void UARTInitialize(void);
extern void UARTSendCharacter(char);
extern void UARTSendString(char*);
extern char UARTReceiveCharacter(void);

#endif
