#include"delay.h"
#include"main.h"
///////////////     ��ʱ����      ///////////////////
void delayUs(u16 d){
	while(--d); 	
}

void delayMs(u16 d){
	while(d--){
		delayUs(248);
		delayUs(248);
	}		
}