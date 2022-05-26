#ifndef _KEY_H_
#define _KEY_H_

#include"main.h"

#define KEY_DELAY_MS	5 //按键防抖延时  单位毫秒

//按键相关函数原型
u8 keySelect(void);
u8 keyStart(void);
u8 keyUP(void);
u8 keyDOWN(void);
u8 keyLEFT(void);
u8 keyRIGHT(void);
u8 keyY(void);
u8 keyX(void);
u8 keyA(void);
u8 keyB(void);

#endif