#ifndef EXTERN_H
#define EXTERN_H


extern void keypadinitialize(void);
extern unsigned char getkeypressed(void);
extern void delay(int count);

extern void lcdinit(void);
extern void lcdstring(char *str);
extern void lcdchar(unsigned char data,unsigned char type);

#endif
