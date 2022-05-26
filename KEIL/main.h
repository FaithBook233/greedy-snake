#ifndef _MAIN_H_
#define _MAIN_H_

#include<reg52.h>

#define u8 unsigned char
#define u16 unsigned int

#define LED_HEIGHT 8  //��Ļ�߶�
#define LED_WIDTH 8  //��Ļ���

#define GAMEOVER 1	//��Ϸʧ�ܷ���ֵ
#define YOUWIN 0    //��Ϸʤ������ֵ

//���ܼ�
sbit KSelect = P3^2;
sbit KStart = P3^3;
//������
sbit beep = P3^4;
//�����
sbit KU = P0^0;
sbit KD	= P0^1;
sbit KL	= P0^2;
sbit KR	= P0^3;
//���Ƽ�
sbit KY	= P0^4;
sbit KA	= P0^5;
sbit KX	= P0^6;
sbit KB	= P0^7;
//���Ŷ˿�ӳ��
sbit COL1 = P2^4;
sbit COL2 = P1^2;
sbit COL3 = P1^3;
sbit COL4 = P2^1;
sbit COL5 = P1^5;
sbit COL6 = P2^2;
sbit COL7 = P2^6;
sbit COL8 = P2^7;
//���ж˿�ӳ��
sbit ROW1 = P2^0;
sbit ROW2 = P2^5;
sbit ROW3 = P1^7;
sbit ROW4 = P2^3;
sbit ROW5 = P1^0;
sbit ROW6 = P1^6;
sbit ROW7 = P1^1;
sbit ROW8 = P1^4;


#endif