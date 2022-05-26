#include"delay.h"
#include"main.h"
///////////////     ÑÓÊ±º¯Êý      ///////////////////
void delayUs(u16 d){
	while(--d); 	
}

void delayMs(u16 d){
	while(d--){
		delayUs(248);
		delayUs(248);
	}		
}