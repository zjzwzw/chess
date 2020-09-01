#ifndef GAMESTATICS_H
#define GAMESTATICS_H
#include "config.h"
class gamestatics
{
public:
    gamestatics();
public:
    int gameMap[20][20];//游戏情况统计，黑1，白-1，无0
    int scoreMap[20][20];//AI下棋分数统计
    bool player;//1黑.0白



};

#endif // GAMESTATICS_H
