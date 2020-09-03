#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "config.h"
#include <QMouseEvent>
#include <cmath>
#include "gamestatics.h"
#include <QMessageBox>
#include <QSound>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    setFixedSize(Margin_*2 + BlockSize *BoardSize,Margin_*2 + BlockSize *BoardSize);
    setWindowTitle("六子棋");
    initGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initGame()
{
    game = new gamestatics;//创建新游戏数据
    for(int i=0;i<BoardSize+1;i++)//初始化棋盘数组
        for(int j= 0 ;j<BoardSize+1;j++)
        {
            game->gameMap[i][j]=0;

        }
    game->player=1;//先手黑棋

}
void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);//绘制棋盘
    painter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿
    QBrush brush;
    brush.setColor(QColor("#EEC085"));//背景颜色
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(0,0,Margin_*2 + BlockSize *BoardSize,Margin_*2 + BlockSize *BoardSize);
    brush.setColor(Qt::black);//中间黑点
    painter.setBrush(brush);
    painter.drawRect(Margin_+BlockSize *BoardSize/2-5,Margin_+BlockSize *BoardSize/2-5,10,10);


    for(int i= 0;i<BoardSize+1 ;i++)
    {
        painter.drawLine(Margin_+BlockSize*i,Margin_,Margin_+BlockSize*i,height()-Margin_);// 竖线
        painter.drawLine(Margin_,Margin_+BlockSize*i,width()-Margin_,Margin_+BlockSize*i);//横线
    }
    //绘制圆点
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
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int x=e->x();
    int y=e->y();

    int list = (x-Margin_)/BlockSize;
    int row = (y-Margin_)/BlockSize;
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

void MainWindow::mouseReleaseEvent(QMouseEvent *e)
{
    int x=(rowpos-Margin_)/BlockSize;
    int y=(listpos-Margin_)/BlockSize;
    if(game->gameMap[x][y]==0)
        {
            if(game->player==1)
                {
                     game->player=0;
                     game->gameMap[x][y]=1;
                     update();
                     //QSound::play();
                }
            else if (game->player==0)
                {
                    game->player=1;
                    game->gameMap[x][y]=-1;
                    update();

                }
            if(game->iswin(x,y))
            {
                update();
                setEnabled(false);
                if(game->player==1)

                QMessageBox::information(this,"win","白棋胜利",QMessageBox::Retry|QMessageBox::Close);
                else if (game->player==0)
                    QMessageBox::information(this,"win","黑棋胜利",QMessageBox::Retry|QMessageBox::Close);

            }

        }
}





















