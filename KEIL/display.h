#ifndef _DISPLAY_H_
#define _DISPLAY_H_

#include"main.h"

#define COL_OFF 0xff
#define COL_ON  0x00
#define ROW_OFF 0x00
#define ROW_ON  0xff

#define LED_DELAY_US    1 //LEDɨ����ʱ   ��λ����

//#define CHARNUM 10
//u8 Number[CHARNUM][8]={
//	{0x00,0x00,0x3e,0x41,0x41,0x41,0x3e,0x00}, //0
//	{0x00,0x00,0x00,0x00,0x21,0x7f,0x01,0x00}, //1
//	{0x00,0x00,0x27,0x45,0x45,0x45,0x39,0x00}, //2
//	{0x00,0x00,0x22,0x49,0x49,0x49,0x36,0x00}, //3
//	{0x00,0x00,0x0c,0x14,0x24,0x7f,0x04,0x00}, //4
//	{0x00,0x00,0x72,0x51,0x51,0x51,0x4e,0x00}, //5
//	{0x00,0x00,0x3e,0x49,0x49,0x49,0x26,0x00}, //6
//	{0x00,0x00,0x40,0x40,0x40,0x4f,0x70,0x00}, //7
//	{0x00,0x00,0x36,0x49,0x49,0x49,0x36,0x00}, //8
//	{0x00,0x00,0x32,0x49,0x49,0x49,0x3e,0x00}, //9
//};

void cleanLED(u8 (*LED)[LED_WIDTH]);//��Ļ��ʼ��
void setCol(u8 col);
void setRow(u8 row);
void setPoint(u8 x,u8 y);//��x��y������ x=[0,7],y =[0,7] 
void display(const u8 (*LED)[LED_WIDTH]);
#endif