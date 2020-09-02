#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


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
    //void mouseReleaseEvent(QMouseEvent *);


private:
    Ui::MainWindow *ui;
    int rowpos;//行
    int listpos;//列
    //gamestatics *game;
    void initGame();



};

#endif // MAINWINDOW_H
