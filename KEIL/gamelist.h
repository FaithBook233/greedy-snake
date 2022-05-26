#ifndef _GAMELIST_H_
#define _GAMELIST_H_

#include"snake.h"

#define GAME_NUMBER 1//当前游戏数量

//函数指针数组
const u8 (*Game[GAME_NUMBER])(void) = {Snake};	

#endif