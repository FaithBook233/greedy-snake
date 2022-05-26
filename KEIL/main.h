#ifndef _MAIN_H_
#define _MAIN_H_

#include<reg52.h>

#define u8 unsigned char
#define u16 unsigned int

#define LED_HEIGHT 8  //屏幕高度
#define LED_WIDTH 8  //屏幕宽度

#define GAMEOVER 1	//游戏失败返回值
#define YOUWIN 0    //游戏胜利返回值

//功能键
sbit KSelect = P3^2;
sbit KStart = P3^3;
//蜂鸣器
sbit beep = P3^4;
//方向键
sbit KU = P0^0;
sbit KD	= P0^1;
sbit KL	= P0^2;
sbit KR	= P0^3;
//控制键
sbit KY	= P0^4;
sbit KA	= P0^5;
sbit KX	= P0^6;
sbit KB	= P0^7;
//横排端口映射
sbit COL1 = P2^4;
sbit COL2 = P1^2;
sbit COL3 = P1^3;
sbit COL4 = P2^1;
sbit COL5 = P1^5;
sbit COL6 = P2^2;
sbit COL7 = P2^6;
sbit COL8 = P2^7;
//纵行端口映射
sbit ROW1 = P2^0;
sbit ROW2 = P2^5;
sbit ROW3 = P1^7;
sbit ROW4 = P2^3;
sbit ROW5 = P1^0;
sbit ROW6 = P1^6;
sbit ROW7 = P1^1;
sbit ROW8 = P1^4;


#endif