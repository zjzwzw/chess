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

    int iswin(int x,int y);
    int f1(int,int);
    int f2(int,int);
    int f3(int,int);
    int f4(int,int);

};

#endif // GAMESTATICS_H
