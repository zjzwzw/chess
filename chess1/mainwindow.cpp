#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include "config.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setFixedSize(Margin*2 + BlockSize *BoardSize,Margin*2 + BlockSize *BoardSize);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::paintEvent(QPaintEvent *e)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing,true);
    for(int i= 0;i<BoardSize+1 ;i++)
    {
        painter.drawLine(Margin+BlockSize*i,Margin,Margin+BlockSize*i,size().height()-Margin);
        painter.drawLine(Margin,Margin+BlockSize*i,size().width()-Margin,Margin+BlockSize*i);
    }
}
