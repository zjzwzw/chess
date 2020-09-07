#include "showpage.h"
#include "ui_showpage.h"
#include "config.h"
#include <QSound>
#include <QPushButton>


showpage::showpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showpage)
{
    ui->setupUi(this);
    setWindowTitle("六子棋");
    setFixedSize(Margin_*2 + BlockSize *BoardSize,Margin_*2 + BlockSize *BoardSize);

    ui->pvp->setStyleSheet("QPushButton{border-image:url(://pt1.png);}"
                           "QPushButton::hover{border-image:url(://pt1__.png);}"
                       "QPushButton::pressed{border-image:url(://pt1_.png);}"
                           );
    ui->pve->setStyleSheet("QPushButton{border-image:url(://pt2.png);}"
                           "QPushButton::hover{border-image:url(://pt2__.png);}"
                       "QPushButton::pressed{border-image:url(://pt2_.png);}"
                           );
    this->setWindowFlags(Qt::Dialog|Qt::WindowCloseButtonHint);//关闭右上角问号



}
showpage::~showpage()
{
    delete ui;
}

void showpage::on_pvp_clicked()
{
    this->hide();
    emit showmain1();
    QSound::play(":/sound.wav");
}

void showpage::on_pve_clicked()
{
    this->hide();
    emit showmain0();
    QSound::play(":/sound.wav");
}

void showpage::reshow()
{
    this->show();
}




