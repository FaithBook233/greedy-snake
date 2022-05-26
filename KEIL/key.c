
#include"key.h"
#include"main.h"
#include"delay.h"

///////////////     °´¼ü¼ì²âº¯Êý      ///////////////////
u8 keySelect(void){
	if(!KSelect){
		delayMs(KEY_DELAY_MS);
		if(!KSelect)
			while(!KSelect);
			return 1;
	}
	return 0;
}
u8 keyStart(void){
	if(!KStart){
		delayMs(KEY_DELAY_MS);
		if(!KStart){
		 	while(!KStart);
			return 1;
		}
	}
	return 0;
}
u8 keyUP(void){
	if(!KU){
		delayMs(KEY_DELAY_MS);
		if(!KU)
			return 1;
	}
	return 0;
}
u8 keyDOWN(void){
	if(!KD){
		delayMs(KEY_DELAY_MS);
		if(!KD)
			return 1;
	}
	return 0;
}
u8 keyLEFT(void){
	if(!KL){
		delayMs(KEY_DELAY_MS);
		if(!KL)
			return 1;
	}
	return 0;
}
u8 keyRIGHT(void){
	if(!KR){
		delayMs(KEY_DELAY_MS);
		if(!KR)return 1;
	}
	return 0;
}
u8 keyY(void){
	if(!KY){
		delayMs(KEY_DELAY_MS);
		if(!KY)
			return 1;
	}
	return 0;
}
u8 keyX(void){
	if(!KX){
		delayMs(KEY_DELAY_MS);
		if(!KX)
			return 1;
	}
	return 0;
}
u8 keyA(void){
	if(!KA){
		delayMs(KEY_DELAY_MS);
		if(!KA)
			return 1;
	}
	return 0;
}
u8 keyB(void){
	if(!KB){
		delayMs(KEY_DELAY_MS);
		if(!KB)
			return 1;
	}
	return 0;
} 
