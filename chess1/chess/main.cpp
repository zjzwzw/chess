#include "showpage.h"
#include <QApplication>
#include "mainwindow.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    showpage m;
    m.show();
    QObject::connect(&m,SIGNAL(showmain()),&w,SLOT(receive()));
    QObject::connect(&w,SIGNAL(signal()),&m,SLOT(reshow()));

    return a.exec();
}
