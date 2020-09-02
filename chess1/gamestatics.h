#ifndef GAMESTATICS_H
#define GAMESTATICS_H
#include "config.h"

class gamestatics
{
public:
    gamestatics();
public:
    int gameMap[BoardSize+1][BoardSize+1];//游戏情况统计，黑1，白-1，无0
    int scoreMap[BoardSize+1][BoardSize+1];//AI下棋分数统计
    bool player;//1黑.0白

};

#endif // GAMESTATICS_H
