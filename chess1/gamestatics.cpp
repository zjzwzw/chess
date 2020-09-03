#include "gamestatics.h"
#include "config.h"
int gamestatics::iswin(int x, int y)
{
    return f1(x,y)||f2(x,y)||f3(x,y)||f4(x,y);
}

int gamestatics::f1(int x, int y)//竖
{
    int i;
    for(i=0;i<6;i++)
    {
        if(y-i>=0&&y+5-i<=BoardSize&&
                gameMap[x][y-i]==gameMap[x][y+1-i]&&
                gameMap[x][y-i]==gameMap[x][y+2-i]&&
                gameMap[x][y-i]==gameMap[x][y+3-i]&&
                gameMap[x][y-i]==gameMap[x][y+4-i]&&
                gameMap[x][y-i]==gameMap[x][y+5-i])
        return  1;
    }
    return 0;
}

int gamestatics::f2(int x, int y)//横
{
    int i;
    for(i=0;i<6;i++)
    {
        if(x-i>=0&&x+5-i<=BoardSize&&
                gameMap[x-i][y]==gameMap[x+1-i][y]&&
                gameMap[x-i][y]==gameMap[x+2-i][y]&&
                gameMap[x-i][y]==gameMap[x+3-i][y]&&
                gameMap[x-i][y]==gameMap[x+4-i][y]&&
                gameMap[x-i][y]==gameMap[x+5-i][y])
        return  1;
    }
    return 0;
}

int gamestatics::f3(int x, int y)//右斜
{
    int i;
    for(i=0;i<6;i++)
    {
        if(y-i>=0&&y+5-i<=BoardSize&&x-i>=0&&x+5-i<=BoardSize&&
                gameMap[x-i][y-i]==gameMap[x+1-i][y+1-i]&&
                gameMap[x-i][y-i]==gameMap[x+2-i][y+2-i]&&
                gameMap[x-i][y-i]==gameMap[x+3-i][y+3-i]&&
                gameMap[x-i][y-i]==gameMap[x+4-i][y+4-i]&&
                gameMap[x-i][y-i]==gameMap[x+5-i][y+5-i])
        return  1;
    }
    return 0;
}

int gamestatics::f4(int x, int y)//左斜
{
    int i;
    for(i=0;i<6;i++)
    {
        if(y-i>=0&&y+5-i<=BoardSize&&x+i<=BoardSize&&x-5+i>=0&&
                gameMap[x+i][y-i]==gameMap[x-1+i][y+1-i]&&
                gameMap[x+i][y-i]==gameMap[x-2+i][y+2-i]&&
                gameMap[x+i][y-i]==gameMap[x-3+i][y+3-i]&&
                gameMap[x+i][y-i]==gameMap[x-4+i][y+4-i]&&
                gameMap[x+i][y-i]==gameMap[x-5+i][y+5-i])
        return  1;
    }
    return 0;
}
