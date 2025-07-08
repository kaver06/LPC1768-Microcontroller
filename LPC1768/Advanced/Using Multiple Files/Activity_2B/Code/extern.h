#ifndef EXTERN_H
#define EXTERN_H


extern void keypadinitialize(void);
extern unsigned char getkeypressed(void);
extern void delay(int count);
int stepper(int degrees, int val);

#endif