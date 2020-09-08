#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"gamestatics.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void paintEvent(QPaintEvent *e);
    void mouseMoveEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
    void calculatescore ();

private slots:
    void receive1();
    void receive0();

    void on_actionRegret_triggered();

private:
    Ui::MainWindow *ui;
    int rowpos;//行
    int listpos;//列
    int row;
    int list;
    gamestatics *game;
    int maxbotrow;
    int maxbotlist;
    void initGame();
signals:
    void signal();



};

#endif // MAINWINDOW_H
