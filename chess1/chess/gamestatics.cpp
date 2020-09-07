#include "gamestatics.h"
#include "config.h"


int gamestatics::iswin(int x, int y)
{
    return f1(x,y)||f2(x,y)||f3(x,y)||f4(x,y);
}

int gamestatics::isfive(int x, int y)//五五禁手
{
    return (f1_(x,y)*f2_(x,y)||f1_(x,y)*f3_(x,y)||f1_(x,y)*f4_(x,y)||
            f2_(x,y)*f3_(x,y)||f2_(x,y)*f4_(x,y)||f3_(x,y)*f4_(x,y));
}

int gamestatics::isfour(int x, int y)//四四禁手
{
    return (f1__(x,y)*f2__(x,y)||f1__(x,y)*f3__(x,y)||f1__(x,y)*f4__(x,y)||
            f2__(x,y)*f3__(x,y)||f2__(x,y)*f4__(x,y)||f3__(x,y)*f4__(x,y));
}

bool gamestatics::isDeadGame()//和棋判断
{
    for(int i=0;i<BoardSize+1;i++)
        for(int j=0;j<BoardSize+1;j++)
    {
        if(!(gameMap[i][j]==1||gameMap[i][j]==-1))
            return false;
    }
    return true;
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

int gamestatics::f1_(int x, int y)//竖活五
{
    int i;
    for(i=0;i<6;i++)
    {
        if(y-i>=0&&y+5-i<=BoardSize&&
                gameMap[x][y-i]!=0&&
                ((gameMap[x][y-1-i]==0&&
                  gameMap[x][y+5-i]==0&&
                  gameMap[x][y-i]==gameMap[x][y+1-i]&&
                gameMap[x][y-i]==gameMap[x][y+2-i]&&
                gameMap[x][y-i]==gameMap[x][y+3-i]&&
                gameMap[x][y-i]==gameMap[x][y+4-i])||
                (gameMap[x][y-1-i]==0&&
                  gameMap[x][y+6-i]==0&&
                 gameMap[x][y+4-i]==0&&
                  gameMap[x][y-i]==gameMap[x][y+1-i]&&
                gameMap[x][y-i]==gameMap[x][y+2-i]&&
                gameMap[x][y-i]==gameMap[x][y+3-i]&&
                gameMap[x][y-i]==gameMap[x][y+5-i])||
                (gameMap[x][y-1-i]==0&&
                 gameMap[x][y+6-i]==0&&
                gameMap[x][y+3-i]==0&&
                 gameMap[x][y-i]==gameMap[x][y+1-i]&&
                gameMap[x][y-i]==gameMap[x][y+2-i]&&
                gameMap[x][y-i]==gameMap[x][y+4-i]&&
                gameMap[x][y-i]==gameMap[x][y+5-i])||
                (gameMap[x][y-1-i]==0&&
                 gameMap[x][y+6-i]==0&&
                gameMap[x][y+2-i]==0&&
                 gameMap[x][y-i]==gameMap[x][y+1-i]&&
                gameMap[x][y-i]==gameMap[x][y+3-i]&&
                gameMap[x][y-i]==gameMap[x][y+4-i]&&
                gameMap[x][y-i]==gameMap[x][y+5-i])||
                (gameMap[x][y-1-i]==0&&
                 gameMap[x][y+6-i]==0&&
                gameMap[x][y+1-i]==0&&
                 gameMap[x][y-i]==gameMap[x][y+2-i]&&
                gameMap[x][y-i]==gameMap[x][y+3-i]&&
                gameMap[x][y-i]==gameMap[x][y+4-i]&&
                gameMap[x][y-i]==gameMap[x][y+5-i]))
                )
        return  1;
    }
    return 0;
}

int gamestatics::f1__(int x,int y)//竖活四
{
    int i;
    for(i=0;i<5;i++)
    {
        if(y-i>=0&&y+4-i<=BoardSize&&
                gameMap[x][y-i]!=0&&
               ( (gameMap[x][y-1-i]==0&&
                  gameMap[x][y+4-i]==0&&
                  gameMap[x][y-i]==gameMap[x][y+1-i]&&
                gameMap[x][y-i]==gameMap[x][y+2-i]&&
                gameMap[x][y-i]==gameMap[x][y+3-i])||
                (gameMap[x][y-1-i]==0&&
                 gameMap[x][y+5-i]==0&&
                 gameMap[x][y+3-1]==0&&
                 gameMap[x][y-i]==gameMap[x][y+1-i]&&
                gameMap[x][y-i]==gameMap[x][y+2-i]&&
                gameMap[x][y-i]==gameMap[x][y+4-i])||
                (gameMap[x][y-1-i]==0&&
                 gameMap[x][y+5-i]==0&&
                 gameMap[x][y+2-1]==0&&
                 gameMap[x][y-i]==gameMap[x][y+1-i]&&
                gameMap[x][y-i]==gameMap[x][y+3-i]&&
                gameMap[x][y-i]==gameMap[x][y+4-i])||
                (gameMap[x][y-1-i]==0&&
                 gameMap[x][y+5-i]==0&&
                 gameMap[x][y+1-1]==0&&
                 gameMap[x][y-i]==gameMap[x][y+2-i]&&
                gameMap[x][y-i]==gameMap[x][y+3-i]&&
                gameMap[x][y-i]==gameMap[x][y+4-i]))
                )
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

int gamestatics::f2_(int x, int y)//横活五
{
    int i;
    for(i=0;i<6;i++)
    {
        if(x-i>=0&&x+5-i<=BoardSize&&
                gameMap[x-i][y]!=0&&
               ( (gameMap[x-1-i][y]==0&&
                  gameMap[x+5-i][y]==0&&
                  gameMap[x-i][y]==gameMap[x+1-i][y]&&
                gameMap[x-i][y]==gameMap[x+2-i][y]&&
                gameMap[x-i][y]==gameMap[x+3-i][y]&&
                gameMap[x-i][y]==gameMap[x+4-i][y])||
                (gameMap[x-1-i][y]==0&&
                 gameMap[x+6-i][y]==0&&
                 gameMap[x+4-i][y]==0&&
                 gameMap[x-i][y]==gameMap[x+1-i][y]&&
                gameMap[x-i][y]==gameMap[x+2-i][y]&&
                gameMap[x-i][y]==gameMap[x+3-i][y]&&
                gameMap[x-i][y]==gameMap[x+5-i][y])||
                (gameMap[x-1-i][y]==0&&
                 gameMap[x+6-i][y]==0&&
                 gameMap[x+3-i][y]==0&&
                 gameMap[x-i][y]==gameMap[x+1-i][y]&&
                gameMap[x-i][y]==gameMap[x+2-i][y]&&
                gameMap[x-i][y]==gameMap[x+4-i][y]&&
                gameMap[x-i][y]==gameMap[x+5-i][y])||
                (gameMap[x-1-i][y]==0&&
                 gameMap[x+6-i][y]==0&&
                 gameMap[x+2-i][y]==0&&
                 gameMap[x-i][y]==gameMap[x+1-i][y]&&
                gameMap[x-i][y]==gameMap[x+3-i][y]&&
                gameMap[x-i][y]==gameMap[x+4-i][y]&&
                gameMap[x-i][y]==gameMap[x+5-i][y])||
                (gameMap[x-1-i][y]==0&&
                 gameMap[x+6-i][y]==0&&
                 gameMap[x+1-i][y]==0&&
                 gameMap[x-i][y]==gameMap[x+2-i][y]&&
                gameMap[x-i][y]==gameMap[x+3-i][y]&&
                gameMap[x-i][y]==gameMap[x+4-i][y]&&
                gameMap[x-i][y]==gameMap[x+5-i][y]))
                )
        return  1;
    }
    return 0;
}

int gamestatics::f2__(int x, int y)//横活四
{
    int i;
    for(i=0;i<5;i++)
    {
        if(x-i>=0&&x+4-i<=BoardSize&&
                gameMap[x-i][y]!=0&&
               ( (gameMap[x-1-i][y]==0&&
                  gameMap[x+4-i][y]==0&&
                  gameMap[x-i][y]==gameMap[x+1-i][y]&&
                gameMap[x-i][y]==gameMap[x+2-i][y]&&
                gameMap[x-i][y]==gameMap[x+3-i][y])||
                (gameMap[x-1-i][y]==0&&
                 gameMap[x+5-i][y]==0&&
                 gameMap[x+3-i][y]==0&&
                 gameMap[x-i][y]==gameMap[x+1-i][y]&&
                gameMap[x-i][y]==gameMap[x+2-i][y]&&
                gameMap[x-i][y]==gameMap[x+4-i][y])||
                (gameMap[x-1-i][y]==0&&
                 gameMap[x+5-i][y]==0&&
                 gameMap[x+2-i][y]==0&&
                 gameMap[x-i][y]==gameMap[x+1-i][y]&&
                gameMap[x-i][y]==gameMap[x+3-i][y]&&
                gameMap[x-i][y]==gameMap[x+4-i][y])||
                (gameMap[x-1-i][y]==0&&
                 gameMap[x+5-i][y]==0&&
                 gameMap[x+1-i][y]==0&&
                 gameMap[x-i][y]==gameMap[x+2-i][y]&&
                gameMap[x-i][y]==gameMap[x+3-i][y]&&
                gameMap[x-i][y]==gameMap[x+4-i][y]))
                )
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

int gamestatics::f3_(int x, int y)//右斜活五
{
    int i;
    for(i=0;i<6;i++)
    {
        if(y-i>=0&&y+5-i<=BoardSize&&x-i>=0&&x+5-i<=BoardSize&&
                gameMap[x-i][y-i]!=0&&
               ( (gameMap[x-1-i][y-1-i]==0&&
                  gameMap[x+5-i][y+5-i]==0&&
                  gameMap[x-i][y-i]==gameMap[x+1-i][y+1-i]&&
                gameMap[x-i][y-i]==gameMap[x+2-i][y+2-i]&&
                gameMap[x-i][y-i]==gameMap[x+3-i][y+3-i]&&
                gameMap[x-i][y-i]==gameMap[x+4-i][y+4-i])||
                (gameMap[x-1-i][y-1-i]==0&&
                 gameMap[x+6-i][y+6-i]==0&&
                 gameMap[x+4-i][y+4-i]==0&&
                 gameMap[x-i][y-i]==gameMap[x+1-i][y+1-i]&&
                gameMap[x-i][y-i]==gameMap[x+2-i][y+2-i]&&
                gameMap[x-i][y-i]==gameMap[x+3-i][y+3-i]&&
                gameMap[x-i][y-i]==gameMap[x+5-i][y+5-i])||
                (gameMap[x-1-i][y-1-i]==0&&
                 gameMap[x+6-i][y+6-i]==0&&
                 gameMap[x+3-i][y+3-i]==0&&
                 gameMap[x-i][y-i]==gameMap[x+1-i][y+1-i]&&
                gameMap[x-i][y-i]==gameMap[x+2-i][y+2-i]&&
                gameMap[x-i][y-i]==gameMap[x+4-i][y+4-i]&&
                gameMap[x-i][y-i]==gameMap[x+5-i][y+5-i])||
                (gameMap[x-1-i][y-1-i]==0&&
                 gameMap[x+6-i][y+6-i]==0&&
                 gameMap[x+2-i][y+2-i]==0&&
                 gameMap[x-i][y-i]==gameMap[x+1-i][y+1-i]&&
                gameMap[x-i][y-i]==gameMap[x+3-i][y+3-i]&&
                gameMap[x-i][y-i]==gameMap[x+4-i][y+4-i]&&
                gameMap[x-i][y-i]==gameMap[x+5-i][y+5-i])||
                (gameMap[x-1-i][y-1-i]==0&&
                 gameMap[x+6-i][y+6-i]==0&&
                 gameMap[x+1-i][y+1-i]==0&&
                 gameMap[x-i][y-i]==gameMap[x+2-i][y+2-i]&&
                gameMap[x-i][y-i]==gameMap[x+3-i][y+3-i]&&
                gameMap[x-i][y-i]==gameMap[x+4-i][y+4-i]&&
                gameMap[x-i][y-i]==gameMap[x+5-i][y+5-i]) )
                )
        return  1;
    }
    return 0;
}

int gamestatics::f3__(int x, int y)//右斜活四
{
    int i;
    for(i=0;i<5;i++)
    {
        if(y-i>=0&&y+4-i<=BoardSize&&x-i>=0&&x+4-i<=BoardSize&&
                gameMap[x-i][y-i]!=0&&
              ( ( gameMap[x-1-i][y-1-i]==0&&
                  gameMap[x+4-i][y+4-i]==0&&
                  gameMap[x-i][y-i]==gameMap[x+1-i][y+1-i]&&
                gameMap[x-i][y-i]==gameMap[x+2-i][y+2-i]&&
                gameMap[x-i][y-i]==gameMap[x+3-i][y+3-i])||
                ( gameMap[x-1-i][y-1-i]==0&&
                  gameMap[x+5-i][y+5-i]==0&&
                  gameMap[x+3-i][y+3-i]==0&&
                  gameMap[x-i][y-i]==gameMap[x+1-i][y+1-i]&&
                 gameMap[x-i][y-i]==gameMap[x+2-i][y+2-i]&&
                 gameMap[x-i][y-i]==gameMap[x+4-i][y+4-i])||
                ( gameMap[x-1-i][y-1-i]==0&&
                  gameMap[x+5-i][y+5-i]==0&&
                  gameMap[x+2-i][y+2-i]==0&&
                  gameMap[x-i][y-i]==gameMap[x+1-i][y+1-i]&&
                 gameMap[x-i][y-i]==gameMap[x+3-i][y+3-i]&&
                 gameMap[x-i][y-i]==gameMap[x+4-i][y+4-i])||
                (gameMap[x-1-i][y-1-i]==0&&
                 gameMap[x+5-i][y+5-i]==0&&
                 gameMap[x+1-i][y+1-i]==0&&
                 gameMap[x-i][y-i]==gameMap[x+2-i][y+2-i]&&
                 gameMap[x-i][y-i]==gameMap[x+3-i][y+3-i]&&
                 gameMap[x-i][y-i]==gameMap[x+4-i][y+4-i]))
                )
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

int gamestatics::f4_(int x, int y)//左斜活五
{
    int i;
    for(i=0;i<6;i++)
    {
        if(y-i>=0&&y+5-i<=BoardSize&&x+i<=BoardSize&&x-5+i>=0&&
                gameMap[x+i][y-i]!=0&&
              (  (gameMap[x+1+i][y-1-i]==0&&
                  gameMap[x-5-i][y+5-i]==0&&
                  gameMap[x+i][y-i]==gameMap[x-1+i][y+1-i]&&
                 gameMap[x+i][y-i]==gameMap[x-2+i][y+2-i]&&
                 gameMap[x+i][y-i]==gameMap[x-3+i][y+3-i]&&
                 gameMap[x+i][y-i]==gameMap[x-4+i][y+4-i])||
                (gameMap[x+1-i][y-1-i]==0&&
                 gameMap[x-6-i][y+6-i]==0&&
                 gameMap[x-4-i][y+4-i]==0&&
                 gameMap[x+i][y-i]==gameMap[x-1+i][y+1-i]&&
                 gameMap[x+i][y-i]==gameMap[x-2+i][y+2-i]&&
                 gameMap[x+i][y-i]==gameMap[x-3+i][y+3-i]&&
                 gameMap[x+i][y-i]==gameMap[x-5+i][y+5-i])||
                (gameMap[x+1-i][y-1-i]==0&&
                 gameMap[x-6-i][y+6-i]==0&&
                 gameMap[x-2-i][y+2-i]==0&&
                 gameMap[x+i][y-i]==gameMap[x-1+i][y+1-i]&&
                 gameMap[x+i][y-i]==gameMap[x-3+i][y+3-i]&&
                 gameMap[x+i][y-i]==gameMap[x-4+i][y+4-i]&&
                 gameMap[x+i][y-i]==gameMap[x-5+i][y+5-i])||
                (gameMap[x+1-i][y-1-i]==0&&
                 gameMap[x-6-i][y+6-i]==0&&
                 gameMap[x-3-i][y+3-i]==0&&
                 gameMap[x+i][y-i]==gameMap[x-1+i][y+1-i]&&
                 gameMap[x+i][y-i]==gameMap[x-2+i][y+2-i]&&
                 gameMap[x+i][y-i]==gameMap[x-4+i][y+4-i]&&
                 gameMap[x+i][y-i]==gameMap[x-5+i][y+5-i])||
                (gameMap[x+1-i][y-1-i]==0&&
                 gameMap[x-6-i][y+6-i]==0&&
                 gameMap[x-1-i][y+1-i]==0&&
                 gameMap[x+i][y-i]==gameMap[x-2+i][y+2-i]&&
                 gameMap[x+i][y-i]==gameMap[x-3+i][y+3-i]&&
                 gameMap[x+i][y-i]==gameMap[x-4+i][y+4-i]&&
                 gameMap[x+i][y-i]==gameMap[x-5+i][y+5-i]) )
                )

        return  1;
    }
    return 0;
}

int gamestatics::f4__(int x, int y)//左斜活四
{
    int i;
    for(i=0;i<5;i++)
    {
        if(y-i>=0&&y+4-i<=BoardSize&&x+i<=BoardSize&&x-4+i>=0&&
                gameMap[x+i][y-i]!=0&&
               ( (gameMap[x+1-i][y-1-i]==0&&
                  gameMap[x-4-i][y+4-i]==0&&
                  gameMap[x+i][y-i]==gameMap[x-1+i][y+1-i]&&
                gameMap[x+i][y-i]==gameMap[x-2+i][y+2-i]&&
                gameMap[x+i][y-i]==gameMap[x-3+i][y+3-i])||
                (gameMap[x+1-i][y-1-i]==0&&
                 gameMap[x-5-i][y+5-i]==0&&
                 gameMap[x-2-i][y+2-i]==0&&
                 gameMap[x+i][y-i]==gameMap[x-1+i][y+1-i]&&
                gameMap[x+i][y-i]==gameMap[x-3+i][y+3-i]&&
                gameMap[x+i][y-i]==gameMap[x-4+i][y+4-i])||
                (gameMap[x+1-i][y-1-i]==0&&
                 gameMap[x-5-i][y+5-i]==0&&
                 gameMap[x-3-i][y+3-i]==0&&
                 gameMap[x+i][y-i]==gameMap[x-1+i][y+1-i]&&
                gameMap[x+i][y-i]==gameMap[x-2+i][y+2-i]&&
                gameMap[x+i][y-i]==gameMap[x-4+i][y+4-i])||
                (gameMap[x+1-i][y-1-i]==0&&
                 gameMap[x-5-i][y+5-i]==0&&
                 gameMap[x-1-i][y+1-i]==0&&
                 gameMap[x+i][y-i]==gameMap[x-2+i][y+2-i]&&
                gameMap[x+i][y-i]==gameMap[x-3+i][y+3-i]&&
                gameMap[x+i][y-i]==gameMap[x-4+i][y+4-i]))
                )
        return  1;
    }
    return 0;
}











