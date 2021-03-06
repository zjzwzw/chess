#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "config.h"
#include <QMouseEvent>
#include <cmath>
#include "gamestatics.h"
#include <QMessageBox>
#include <QSound>
#include <QPushButton>
#include <QString>
#include "showpage.h"
#include <QTimer>
#include <time.h>
#include <stdlib.h>



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);//鼠标追踪设置
    setFixedSize(Margin_*2 + BlockSize *BoardSize,Margin_*2 + BlockSize *BoardSize);
    setWindowTitle("六子棋");
    initGame();

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initGame()//初始化游戏数据
{
    game = new gamestatics;//创建新游戏数据
    for(int i=0;i<BoardSize+1;i++)//初始化棋盘数组.Ai得分数组
        for(int j= 0 ;j<BoardSize+1;j++)
        {
            game->gameMap[i][j]=0;
            game->scoreMap[i][j]=0;
        }
    game->player=1;//先手黑棋

}
void MainWindow::paintEvent(QPaintEvent *e)//绘画事件
{
    QPainter painter(this);//绘制棋盘
    painter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿
    QBrush brush;
    brush.setColor(QColor("#EEC085"));//背景颜色
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(0,0,Margin_*2 + BlockSize *BoardSize,Margin_*2 + BlockSize *BoardSize);//填充画布颜色
    brush.setColor(Qt::black);//中间黑点
    painter.setBrush(brush);
    painter.drawRect(Margin_+BlockSize *BoardSize/2-5,Margin_+BlockSize *BoardSize/2-5,10,10);


    for(int i= 0;i<BoardSize+1 ;i++)
    {
        painter.drawLine(Margin_+BlockSize*i,Margin_,Margin_+BlockSize*i,height()-Margin_);// 竖线
        painter.drawLine(Margin_,Margin_+BlockSize*i,width()-Margin_,Margin_+BlockSize*i);//横线
    }

    //绘制圆点,白棋白点，黑棋黑点
    if(game->player==1)
    {
        brush.setColor(Qt::black);
        painter.setBrush(brush);
        painter.drawEllipse(rowpos-5,listpos-5,10,10);
    }
    else if(game->player==0)
    {
        brush.setColor(Qt::white);
        painter.setBrush(brush);
        painter.drawEllipse(rowpos-5,listpos-5,10,10);
    }

    //绘制棋子,遍历整个棋盘的点
    for(int i=0;i<BoardSize+1;i++)
        for(int j=0;j<BoardSize+1;j++)
        {
            if(game->gameMap[i][j]==1)
            {
                brush.setColor(Qt::black);
                painter.setBrush(brush);
                painter.drawEllipse(QPoint(Margin_+i*BlockSize,Margin_+j*BlockSize),ChessRadius,ChessRadius);
            }
            else if(game->gameMap[i][j]==-1)
            {
                brush.setColor(Qt::white);
                painter.setBrush(brush);
                painter.drawEllipse(QPoint(Margin_+i*BlockSize,Margin_+j*BlockSize),ChessRadius,ChessRadius);

            }
        }



}
void MainWindow::mouseMoveEvent(QMouseEvent *e)//鼠标追踪
{
    //实现鼠标和十字交叉处模糊距离的判断

    int x=e->x();
    int y=e->y();

    int list = (x-Margin_)/BlockSize;//列
    int row = (y-Margin_)/BlockSize;//行

    //记鼠标所在方格左上角点为标记点，计算四个点和鼠标所在位置的距离大小
    int rowlenth = Margin_ + list*BlockSize;
    int listlenth = Margin_+ row * BlockSize;
    if(sqrt((x-rowlenth)*(x-rowlenth)+(y-listlenth)*(y-listlenth))<Positon)
    {
        rowpos = Margin_ + list*BlockSize;
        listpos = Margin_+ row * BlockSize;
    }
    else if(sqrt((x-rowlenth-BlockSize)*(x-rowlenth-BlockSize)+(y-listlenth)*(y-listlenth))<Positon)
    {
        rowpos=Margin_ + list*BlockSize+BlockSize;
        listpos = Margin_+ row * BlockSize;

    }
    else if(sqrt((x-rowlenth)*(x-rowlenth)+(y-listlenth-BlockSize)*(y-listlenth-BlockSize))<Positon)
    {
        listpos=Margin_+ row * BlockSize+BlockSize;
        rowpos = Margin_ + list*BlockSize;
    }
    else if(sqrt((x-rowlenth-BlockSize)*(x-rowlenth-BlockSize)+(y-listlenth-BlockSize)*(y-listlenth-BlockSize))<Positon)
    {
        listpos=Margin_+ row * BlockSize+BlockSize;
        rowpos=Margin_ + list*BlockSize+BlockSize;
    }
    update();
}

void MainWindow::mouseReleaseEvent(QMouseEvent *e)//下棋
{
    row=(rowpos-Margin_)/BlockSize;
    list=(listpos-Margin_)/BlockSize;
    int x=(rowpos-Margin_)/BlockSize;//放置棋子的坐标位置
    int y=(listpos-Margin_)/BlockSize;
    if(game->gameMap[x][y]==0)//该位置没有棋子
        {
            if(game->player==1&&game->gametype==1)
                {
                     game->player=0;
                     game->gameMap[x][y]=1;
                     update();
                     QSound::play("://sound.wav");

                }
            else if (game->player==0&&game->gametype==1)
                {
                    game->player=1;
                    game->gameMap[x][y]=-1;
                    update();
                    QSound::play("://sound.wav");


                }
            else if (game->player==1&&game->gametype==0)
            {
                game->player=0;
                game->gameMap[x][y]=1;
                update();
                QSound::play("://sound.wav");
                //黑棋赢了就不再让人机下棋，否则继续
                switch (game->iswin(x,y))
                {
                     case 1:  break;
                case 0: {
                    //QTimer::singleShot(700,this,SLOT(calculatescore()));
                    AIPlay();
                    game->gameMap[maxbotrow][maxbotlist]=-1;
                    game->player=1;x=maxbotrow;y=maxbotlist;update();break;}
                }
            }

            if(game->iswin(x,y)&&game->gametype!=-1)
            {
                update();
                setEnabled(false);
                if(game->player==1)

                {
                    QPushButton *retry=new QPushButton("返回主菜单");
                    QPushButton *close=new QPushButton("退出游戏");
                    QMessageBox *box = new QMessageBox;

                    box->setWindowTitle("win");
                    box->setText("白棋胜利");
                    box->addButton(retry,QMessageBox::AcceptRole);//枚举类型
                    box->addButton(close,QMessageBox::RejectRole);
                    box->show();
                    box->exec();//等待用户操作
                    if(box->clickedButton()==close)
                    {
                        this->close();
                    }
                    else
                    {
                        delete game;
                        this->close();
                        emit signal();
                        initGame();
                        setEnabled(true);
                    }
                }
                else if (game->player==0)
                {
                    QPushButton *retry=new QPushButton("返回主菜单");
                    QPushButton *close=new QPushButton("退出游戏");
                    QMessageBox *box = new QMessageBox;

                    box->setWindowTitle("win");
                    box->setText("黑棋胜利");
                    box->addButton(retry,QMessageBox::AcceptRole);//枚举类型
                    box->addButton(close,QMessageBox::RejectRole);
                    box->show();
                    box->exec();//等待用户操作
                    if(box->clickedButton()==close)
                    {
                        this->close();
                    }
                    else
                    {
                        delete  game;
                        this->close();
                        emit signal();
                        initGame();
                        setEnabled(true);
                    }
                }
                game->gameover=0;

            }
            if(game->isfive(x,y)==1&&game->player==0&&game->gameover==1)
            {
                update();
                setEnabled(false);
                {
                    QPushButton *retry=new QPushButton("返回主菜单");
                    QPushButton *close=new QPushButton("退出游戏");
                    QMessageBox *box = new QMessageBox;

                    box->setWindowTitle("黑棋出局");
                    box->setText("黑棋违反规则五五禁手");
                    box->addButton(retry,QMessageBox::AcceptRole);//枚举类型
                    box->addButton(close,QMessageBox::RejectRole);
                    box->show();
                    box->exec();//等待用户操作
                    if(box->clickedButton()==close)
                    {
                        this->close();
                    }
                    else
                    {
                        delete  game;
                        this->close();
                        emit signal();
                        initGame();
                        setEnabled(true);

                    }
                }

            }
            if(game->isfour(x,y)==1&&game->player==0&&game->gameover==1&&game->isfive(x,y)==0)
            {
                update();
                setEnabled(false);
                {
                    QPushButton *retry=new QPushButton("返回主菜单");
                    QPushButton *close=new QPushButton("退出游戏");
                    QMessageBox *box = new QMessageBox;

                    box->setWindowTitle("黑棋出局");
                    box->setText("黑棋违反规则四四禁手");
                    box->addButton(retry,QMessageBox::AcceptRole);//枚举类型
                    box->addButton(close,QMessageBox::RejectRole);
                    box->show();
                    box->exec();//等待用户操作
                    if(box->clickedButton()==close)
                    {
                        this->close();
                    }
                    else
                    {
                        delete  game;
                        this->close();
                        emit signal();
                        initGame();
                        setEnabled(true);
                    }
                }
                if(game->isDeadGame()==true)
                {
                    QPushButton *retry=new QPushButton("返回主菜单");
                    QPushButton *close=new QPushButton("退出游戏");
                    QMessageBox *box = new QMessageBox;

                    box->setWindowTitle("draw");
                    box->setText("平局！");
                    box->addButton(retry,QMessageBox::AcceptRole);//枚举类型
                    box->addButton(close,QMessageBox::RejectRole);
                    box->show();
                    box->exec();//等待用户操作
                    if(box->clickedButton()==close)
                    {
                        this->close();
                    }
                    else
                    {
                        delete  game;
                        this->close();
                        emit signal();
                        initGame();
                        setEnabled(true);
                    }
                }

            }
    }
}


void MainWindow::AIPlay()//计算人机下棋评分
{

        for(int row=0;row<BoardSize+1;row++)
            for(int list=0;list<BoardSize+1;list++)
            {
                if(game->gameMap[row][list]==0)
                {
                    for(int y=-1;y<=1;y++)
                        for(int x=-1;x<=1;x++)
                        {
                            int personNum=0;
                            int botNum=0;
                            int emptyNum=0;
                            if(!(y==0&&x==0))
                            {
                                for(int i=1;i<6;i++)
                                    if(row+i*x>0&&row+i*x<BoardSize+1&&
                                            list+i*y>0&&list+i*y<BoardSize+1&&
                                            game->gameMap[row+i*x][list+i*y]==1)
                                    {
                                        personNum++;
                                    }
                                    else if (row+i*x>0&&row+i*x<BoardSize+1&&
                                             list+i*y>0&&list+i*y<BoardSize+1&&
                                             game->gameMap[row+i*x][list+i*y]==0)
                                    {
                                        emptyNum++;
                                        break;
                                    }
                                    else
                                    {
                                        break;
                                    }
                                if(personNum==1)
                                    game->scoreMap[row][list]+=5;
                                else if (personNum==2)
                                {
                                    if(emptyNum==1)
                                     game->scoreMap[row][list]+=15;
                                    game->scoreMap[row][list]+=10;
                                }
                                else if (personNum==3)
                                {
                                    if(emptyNum==1)
                                        game->scoreMap[row][list]+=25;
                                    game->scoreMap[row][list]+=20;
                                }
                                else if (personNum==4)
                                {
                                    if(emptyNum==1)
                                        game->scoreMap[row][list]+=150;
                                    game->scoreMap[row][list]+=50;

                                }
                                else if(personNum==5)
                                    game->scoreMap[row][list]+=5000;
                             emptyNum=0;
                             for(int i=1;i<6;i++)
                                 if(row+i*x>0&&row+i*x<BoardSize+1&&
                                         list+i*y>0&&list+i*y<BoardSize+1&&
                                         game->gameMap[row+i*x][list+i*y]==-1)
                                 {
                                     botNum++;
                                 }
                                 else if (row+i*x>0&&row+i*x<BoardSize+1&&
                                          list+i*y>0&&list+i*y<BoardSize+1&&
                                          game->gameMap[row+i*x][list+i*y]==0)
                                 {
                                     emptyNum++;
                                     break;

                                 }
                                 else {
                                     break;
                                 }
                             if(botNum==0)
                                 game->scoreMap[row][list]+=5;
                             else if (botNum==1)
                             {
                                 game->scoreMap[row][list]+=10;
                             }
                             else if (botNum==2)
                             {
                                 if(emptyNum==1)
                                     game->scoreMap[row][list]+=20;
                                 game->scoreMap[row][list]+=15;

                             }
                             else if (botNum==3)
                             {
                                if(emptyNum==1)
                                     game->scoreMap[row][list]+=35;
                                game->scoreMap[row][list]+=30;

                             }
                             else if(botNum==4)
                             {
                                 if(emptyNum==1)
                                     game->scoreMap[row][list]+=70;
                                 game->scoreMap[row][list]+=50;

                             }
                             else if(botNum==5)
                                 game->scoreMap[row][list]+=100000;
                            }

                        }
                }
            }
        maxbotrow=0;
        maxbotlist=0;
        std::vector<std::pair<int,int>> max;
        for(int i=0;i<BoardSize+1;i++)
            for(int j=0;j<BoardSize+1;j++)
            {
                if(game->gameMap[i][j]==0)
                {
                if(game->scoreMap[i][j]>game->scoreMap[maxbotrow][maxbotlist])
                {
                    max.clear();//清空容器
                    maxbotrow=i;
                    maxbotlist=j;
                    max.push_back(std::make_pair(maxbotrow,maxbotlist));
                }
                else if(game->scoreMap[i][j]==game->scoreMap[maxbotrow][maxbotlist])
                {
                    max.push_back(std::make_pair(i,j));
                }
                }
            }
        srand((unsigned)time(0));
        int index=rand()%max.size();
        std::pair<int,int>maxpoint = max.at(index);
        maxbotrow=maxpoint.first;
        maxbotlist=maxpoint.second;


}

void MainWindow::receive1()//接收主界面信号，展示游戏界面
{
    this->show();
    game->gametype=1;
}

void MainWindow::receive0()
{
    this->show();
    game->gametype=0;
}

void MainWindow::receive_1()
{
    this->show();
    game->gametype=-1;
    game->gameMap[BoardSize/2][BoardSize/2]=1;
    game->player=0;
    maxbotrow=BoardSize/2;
    maxbotlist=BoardSize/2;
    update();
    this->startTimer(700);
}

void MainWindow::timerEvent(QTimerEvent *e)//人机自动下棋
{
    if(game->gametype==-1)
    {
        if(game->player==0&&!game->iswin(maxbotrow,maxbotlist))
        {
            AIPlay();
            game->gameMap[maxbotrow][maxbotlist]=-1;
            QSound::play("://sound.wav");
            update();
            game->player=1;
        }
        else if(game->player==1&&!game->iswin(maxbotrow,maxbotlist))
        {
            AIPlay();
            game->gameMap[maxbotrow][maxbotlist]=1;
            QSound::play("://sound.wav");
            update();
            game->player=0;
        }
        if(game->iswin(maxbotrow,maxbotlist))
        {
            update();
            setEnabled(false);
            if(game->player==1)
            {
                QPushButton *retry=new QPushButton("返回主菜单");
                QPushButton *close=new QPushButton("退出游戏");
                QMessageBox *box = new QMessageBox;

                box->setWindowTitle("win");
                box->setText("白棋胜利");
                box->addButton(retry,QMessageBox::AcceptRole);//枚举类型
                box->addButton(close,QMessageBox::RejectRole);
                box->show();
                box->exec();//等待用户操作
                if(box->clickedButton()==close)
                {
                    this->close();
                }
                else
                {
                    delete game;
                    this->close();
                    emit signal();
                    initGame();
                    setEnabled(true);
                }
            }
            else if (game->player==0)
            {
                QPushButton *retry=new QPushButton("返回主菜单");
                QPushButton *close=new QPushButton("退出游戏");
                QMessageBox *box = new QMessageBox;

                box->setWindowTitle("win");
                box->setText("黑棋胜利");
                box->addButton(retry,QMessageBox::AcceptRole);//枚举类型
                box->addButton(close,QMessageBox::RejectRole);
                box->show();
                box->exec();//等待用户操作
                if(box->clickedButton()==close)
                {
                    this->close();
                }
                else
                {
                    delete  game;
                    this->close();
                    emit signal();
                    initGame();
                    setEnabled(true);
                }
            }
        }
    }

}

void MainWindow::on_actionRegret_triggered()//悔棋按钮
{
    bool havechess = false;
    for(int i=0;i<BoardSize+1;i++)
        for(int j=0;j<BoardSize+1;j++)
        {
            if(game->gameMap[i][j]!=0)
              {
                havechess = true;
                break;
            }

        }
    if(havechess==true)
    {
        if(game->gametype==1)
    {
        game->gameMap[row][list]=0;
        if(game->player==1)
            game->player=0;
        else
        {
            game->player=1;
        }
        update();
    }
    else if(game->gametype==0)
    {
         game->gameMap[maxbotrow][maxbotlist]=0;
         game->gameMap[row][list]=0;
         update();
    }
    }
    else{
        QMessageBox *box = new QMessageBox;
        box->setWindowTitle("警告!");
        box->setText("害没下棋呢就想悔棋?");
        box->show();
        box->exec();
    }
}

