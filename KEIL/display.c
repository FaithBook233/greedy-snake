#include"display.h"
#include"main.h"
#include"delay.h"
#include"display.h"
#include"key.h"

//ÆÁÄ»³õÊ¼»¯
void cleanLED(u8 (*LED)[LED_WIDTH]){
	u8 i,j;
 	for(i = 0;i<8;i++)
		for(j = 0;j<8;j++)
			LED[i][j] = 0;
}
void setCol(u8 col){
	COL8 = col%2;
	COL7 = col/2%2;
	COL6 = col/4%2;
	COL5 = col/8%2;
	COL4 = col/16%2;
	COL3 = col/32%2;
	COL2 = col/64%2;
	COL1 = col/128%2;
}
void setRow(u8 row){
	ROW8 = row%2;
	ROW7 = row/2%2;
	ROW6 = row/4%2;
	ROW5 = row/8%2;
	ROW4 = row/16%2;
	ROW3 = row/32%2;
	ROW2 = row/64%2;
	ROW1 = row/128%2; 	
}

//£¨x£¬y£©µãÁÁ x=[0,7],y =[0,7] 
void setPoint(u8 x,u8 y){
	
	u8 col = 0x80;
	u8 row = 0x80;
	setRow(row>>=y);
	setCol(~(col>>=x));
	delayUs(LED_DELAY_US);
	setCol(0xff);
}

void display(const u8 (*LED)[LED_WIDTH]){
	u8 i,j;
	for(i = 0;i<LED_HEIGHT;i++){
	 	for(j = 0;j<LED_WIDTH;j++){
			if(!LED[i][j])continue;
			setPoint(j,i);
		}
	}
}

