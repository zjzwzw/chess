#ifndef GAMESTATICS_H
#define GAMESTATICS_H
#include "config.h"

class gamestatics
{
public:
    gamestatics(){}
public:
    int gameMap[BoardSize+1][BoardSize+1];//游戏情况统计，黑1，白-1，无0
    int scoreMap[BoardSize+1][BoardSize+1];//AI下棋分数统计
    bool player=1;//1黑.0白
    bool gameover=1;//游戏是否结束

    int iswin(int x,int y);
    int isfive(int x,int y);
    int isfour(int x,int y);
    bool isDeadGame();
    int f1(int,int);
    int f1_(int,int);
    int f1__(int,int);
    int f2(int,int);
    int f2_(int,int);
    int f2__(int,int);
    int f3(int,int);
    int f3_(int,int);
    int f3__(int,int);
    int f4(int,int);
    int f4_(int,int);
    int f4__(int,int);

};

#endif // GAMESTATICS_H
