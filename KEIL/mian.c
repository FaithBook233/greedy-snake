#include<reg52.h>

#include"main.h"
#include"delay.h"
#include"key.h"
#include"display.h"
#include"gamelist.h"



void main()						  
{
	u8 gameSelect = 0; //”Œœ∑—°‘Ò
	while(1)
	{
		(*Game[gameSelect])();
			
	} 	
}