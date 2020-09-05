#include "showpage.h"
#include "ui_showpage.h"
#include "config.h"


showpage::showpage(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showpage)
{
    ui->setupUi(this);
    setWindowTitle("六子棋");
    setFixedSize(Margin_*2 + BlockSize *BoardSize,Margin_*2 + BlockSize *BoardSize);

}
showpage::~showpage()
{
    delete ui;
}

void showpage::on_pvp_clicked()
{
    this->hide();
    emit showmain();
    this->gametype=1;
}

void showpage::on_pve_clicked()
{
    this->hide();
    emit showmain();
    this->gametype=0;
}

void showpage::reshow()
{
    this->show();
}




