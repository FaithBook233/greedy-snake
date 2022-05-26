#include"snake.h"
#include<stdlib.h>
#include"key.h"
#include"display.h"
#include"main.h"
#include"delay.h"
///////////////////////////////////////////////
///////////////     ̰����     ////////////////
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
	}while(led[*y][*x]); //�����������Ϊ1���������ֱ�����������Ϊ��
	led[*y][*x] = 1;
}
void showDegree(u8 degree){
	u8 i,j;
	for(i = 0;i<LED_HEIGHT;i++)
		for(j = 0;j<=degree;j++)
			setPoint(j,i);	
}
u8 Snake(void){
	#define BLOCKNUM 64	//���������С
 	u8 degree = 0,snakeNum = 1,dirX = 1,dirY = 0,dirOX,dirOY; //�Ѷȵȼ�����ǰ�����ȣ��������
	u8 LED[LED_HEIGHT][LED_WIDTH];//������ʾ����
	u8 headX = 0,headY = 0,appleX,appleY;	//��ͷλ�ñ���   ʳ��λ�ñ���
	u8 t,time; //�ƶ��ٶȿ��Ʊ���
	u8 r = 0;
	//����λ������
	u8 snakeX[BLOCKNUM];
	u8 snakeY[BLOCKNUM];
	while(1){ //�Ѷ�ѡ��
		showDegree(degree);
		if(keySelect())
			if(degree<7)degree++;
			else degree = 0;
		else if(keyStart())break;
	}	
	time = 100-degree*10;//��ʱ����
	cleanLED(LED);//����
	LED[headY][headX] = 1;//��ʾ��ͷ
	//����ͷ���浽�����һλ
	snakeX[0] = headX;
	snakeY[0] = headY;
	//�˶������ʼ��
	dirOX = dirX;
	dirOY = dirY;
	//���ʳ����ֵ�λ��
	randXY(&appleX,&appleY,LED,t);
	t = 0;
	while(1){ 
		/*
		  ��Ϸ��ѭ��
		*/
		display(LED);//��ʾ	
//		//����������⣬��ֹ����İ����жϣ���ȡ���һ�εķ���		
		if(dirY!=-1 && (keyUP()||keyY()))setDir(&dirX,&dirY,-1);
		else if(dirY!=1 &&(keyDOWN()||keyA()))setDir(&dirX,&dirY,1);
		else if(dirX!=-1 &&(keyLEFT()||keyX()))setDir(&dirY,&dirX,-1);
		else if(dirX!=1 &&(keyRIGHT()||keyB()))setDir(&dirY,&dirX,1);
		
		//��ͣ
		if(keyStart())
			while(!keyStart())
				display(LED);
							 	
		/*
			ÿ��һ��ʱ������ƶ�
			���´��빦��Ϊ�ƶ��ж����ƶ�����
		*/
		r++;//ʱ������
		if(t++ >time){	 //����Ե��ƶ�
			t = 0;
			if((dirX!=0 && dirOX ==0)||(dirY!=0 && dirOY==0)){//�Ϸ�������������
			 	dirOX = dirX;
				dirOY = dirY;
			}				
			setHead(&headX,dirOX);	//���պϷ������뷽����ǰ�˶�һ��
			setHead(&headY,dirOY);			
			if(headY == appleY && headX == appleX){		//����ͷ���е���һλ��ʳ��
					//����ӳ�
					snakeNum++;
				 	snakeX[snakeNum-1] = appleX;
					snakeY[snakeNum-1] = appleY;
					//��һ��ƻ��
					randXY(&appleX,&appleY,LED,r);
			}else if(!LED[headY][headX]){				//��ǰ��Ϊ���ϰ���
				 //ǰ�����ϰ�
				moveSnakeXY(snakeX,snakeNum,headX);
				moveSnakeXY(snakeY,snakeNum,headY);
			}else if(headX == snakeX[0]&& headY == snakeY[0]){//
				moveSnakeXY(snakeX,snakeNum,headX);
				moveSnakeXY(snakeY,snakeNum,headY);
			}else {				//��ǰ�����ϰ����壬�򴥷������������ش���ֵ			
				return GAMEOVER;
			}
			changeLED(LED,snakeX,snakeY,snakeNum,appleX,appleY);//��ʾ����ˢ��
		}
	}
	return GAMEOVER;//��Ϸ���������ش�����Ϣ
}	 												