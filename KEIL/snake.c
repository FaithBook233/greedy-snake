#include"snake.h"
#include<stdlib.h>
#include"key.h"
#include"display.h"
#include"main.h"
#include"delay.h"
///////////////////////////////////////////////
///////////////     贪吃蛇     ////////////////
///////////////////////////////////////////////


void setDir(u8 *dir_1,u8 *dir_2,u8 value){
 	*dir_1 = 0;
	*dir_2 = value;
}

void setHead(u8 *z,u8 dir){
	*z+=dir;
	if(*z == -1)*z = 7;
	else if(*z == 8)*z = 0;
}

void moveSnakeXY(u8 *snakeXY,const u8 num,const u8 XY){
	u8 i = 0;
	while(i<num-1){
		snakeXY[i] = snakeXY[i+1];
		i++;
	}
	snakeXY[i] = XY;
}

void changeLED(u8 (*led)[LED_WIDTH],const u8 *x,const u8 *y,u8 num,u8 apx,u8 apy){
	int i = 0;
	cleanLED(led);
	while(i < num){
	 	led[y[i]][x[i]] = 1;
		i++;
	}
	led[apy][apx] = 1;																	  	
}

void randXY(u8 *x,u8 *y,u8 (*led)[LED_WIDTH],u8 t){
	srand(t);
	do{
	 	*x = rand()%8;
		*y = rand()%8; 
	}while(led[*y][*x]); //若这个点上面为1，则继续，直到这个点上面为空
	led[*y][*x] = 1;
}
void showDegree(u8 degree){
	u8 i,j;
	for(i = 0;i<LED_HEIGHT;i++)
		for(j = 0;j<=degree;j++)
			setPoint(j,i);	
}
u8 Snake(void){
	#define BLOCKNUM 64	//蛇身数组大小
 	u8 degree = 0,snakeNum = 1,dirX = 1,dirY = 0,dirOX,dirOY; //难度等级，当前蛇身长度，方向变量
	u8 LED[LED_HEIGHT][LED_WIDTH];//界面显示矩阵
	u8 headX = 0,headY = 0,appleX,appleY;	//蛇头位置变量   食物位置变量
	u8 t,time; //移动速度控制变量
	u8 r = 0;
	//蛇身位置数组
	u8 snakeX[BLOCKNUM];
	u8 snakeY[BLOCKNUM];
	while(1){ //难度选择
		showDegree(degree);
		if(keySelect())
			if(degree<7)degree++;
			else degree = 0;
		else if(keyStart())break;
	}	
	time = 100-degree*10;//延时长度
	cleanLED(LED);//清屏
	LED[headY][headX] = 1;//显示蛇头
	//将蛇头保存到数组第一位
	snakeX[0] = headX;
	snakeY[0] = headY;
	//运动方向初始化
	dirOX = dirX;
	dirOY = dirY;
	//随机食物出现的位置
	randXY(&appleX,&appleY,LED,t);
	t = 0;
	while(1){ 
		/*
		  游戏主循环
		*/
		display(LED);//显示	
//		//按键操作检测，防止多余的按键判断，获取最近一次的方向		
		if(dirY!=-1 && (keyUP()||keyY()))setDir(&dirX,&dirY,-1);
		else if(dirY!=1 &&(keyDOWN()||keyA()))setDir(&dirX,&dirY,1);
		else if(dirX!=-1 &&(keyLEFT()||keyX()))setDir(&dirY,&dirX,-1);
		else if(dirX!=1 &&(keyRIGHT()||keyB()))setDir(&dirY,&dirX,1);
		
		//暂停
		if(keyStart())
			while(!keyStart())
				display(LED);
							 	
		/*
			每隔一定时间进行移动
			以下代码功能为移动判断与移动操作
		*/
		r++;//时间种子
		if(t++ >time){	 //间隔性的移动
			t = 0;
			if((dirX!=0 && dirOX ==0)||(dirY!=0 && dirOY==0)){//合法方向输入引用
			 	dirOX = dirX;
				dirOY = dirY;
			}				
			setHead(&headX,dirOX);	//按照合法的输入方向提前运动一次
			setHead(&headY,dirOY);			
			if(headY == appleY && headX == appleX){		//若蛇头运行的下一位是食物
					//数组加长
					snakeNum++;
				 	snakeX[snakeNum-1] = appleX;
					snakeY[snakeNum-1] = appleY;
					//下一个苹果
					randXY(&appleX,&appleY,LED,r);
			}else if(!LED[headY][headX]){				//若前方为无障碍物
				 //前方无障碍
				moveSnakeXY(snakeX,snakeNum,headX);
				moveSnakeXY(snakeY,snakeNum,headY);
			}else if(headX == snakeX[0]&& headY == snakeY[0]){//
				moveSnakeXY(snakeX,snakeNum,headX);
				moveSnakeXY(snakeY,snakeNum,headY);
			}else {				//若前方有障碍物体，则触发蜂鸣器并返回错误值			
				return GAMEOVER;
			}
			changeLED(LED,snakeX,snakeY,snakeNum,appleX,appleY);//显示矩阵刷新
		}
	}
	return GAMEOVER;//游戏结束，返回错误信息
}	 												