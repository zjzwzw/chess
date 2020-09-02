#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "config.h"
#include <QMouseEvent>
#include <cmath>
#include "gamestatics.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMouseTracking(true);
    setFixedSize(Margin*2 + BlockSize *BoardSize,Margin*2 + BlockSize *BoardSize);
    setWindowTitle("六子棋");
    initGame();
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::initGame()
{
   // game = new gamestatics;
}
void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);//绘制棋盘
    painter.setRenderHint(QPainter::Antialiasing,true);//抗锯齿
    QBrush brush;
    brush.setColor(QColor("#EEC085"));//背景颜色
    brush.setStyle(Qt::SolidPattern);
    painter.setBrush(brush);
    painter.drawRect(0,0,Margin*2 + BlockSize *BoardSize,Margin*2 + BlockSize *BoardSize);
    brush.setColor(Qt::black);//中间黑点
    painter.setBrush(brush);
    painter.drawRect(Margin+BlockSize *BoardSize/2-5,Margin+BlockSize *BoardSize/2-5,10,10);


    for(int i= 0;i<BoardSize+1 ;i++)
    {
        painter.drawLine(Margin+BlockSize*i,Margin,Margin+BlockSize*i,height()-Margin);// 竖线
        painter.drawLine(Margin,Margin+BlockSize*i,width()-Margin,Margin+BlockSize*i);//横线
    }
    //绘制圆点
    brush.setColor(Qt::blue);
    painter.setBrush(brush);
    painter.drawEllipse(rowpos-5,listpos-5,10,10);

}
void MainWindow::mouseMoveEvent(QMouseEvent *e)
{
    int x=e->x();
    int y=e->y();

    int list = (x-Margin)/BlockSize;
    int row = (y-Margin)/BlockSize;
    int rowlenth = Margin + list*BlockSize;
    int listlenth = Margin+ row * BlockSize;
    if(sqrt((x-rowlenth)*(x-rowlenth)+(y-listlenth)*(y-listlenth))<Positon)
    {
        rowpos = Margin + list*BlockSize;
        listpos = Margin+ row * BlockSize;
    }
    else if(sqrt((x-rowlenth-BlockSize)*(x-rowlenth-BlockSize)+(y-listlenth)*(y-listlenth))<Positon)
    {
        rowpos=Margin + list*BlockSize+BlockSize;
        listpos = Margin+ row * BlockSize;

    }
    else if(sqrt((x-rowlenth)*(x-rowlenth)+(y-listlenth-BlockSize)*(y-listlenth-BlockSize))<Positon)
    {
        listpos=Margin+ row * BlockSize+BlockSize;
        rowpos = Margin + list*BlockSize;
    }
    else if(sqrt((x-rowlenth-BlockSize)*(x-rowlenth-BlockSize)+(y-listlenth-BlockSize)*(y-listlenth-BlockSize))<Positon)
    {
        listpos=Margin+ row * BlockSize+BlockSize;
        rowpos=Margin + list*BlockSize+BlockSize;
    }
    update();


}





















