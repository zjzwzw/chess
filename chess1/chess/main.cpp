#include "showpage.h"
#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    showpage m;
    m.show();
    QObject::connect(&m,SIGNAL(showmain1()),&w,SLOT(receive1()));
    QObject::connect(&m,SIGNAL(showmain0()),&w,SLOT(receive0()));
    QObject::connect(&w,SIGNAL(signal()),&m,SLOT(reshow()));

    return a.exec();
}
