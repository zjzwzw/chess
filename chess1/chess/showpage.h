#ifndef SHOWPAGE_H
#define SHOWPAGE_H

#include <QDialog>


namespace Ui {
class showpage;
}

class showpage : public QDialog
{
    Q_OBJECT

public:
    explicit showpage(QWidget *parent = nullptr);
    ~showpage();
    bool gametype;//游戏模式，1为人人，0为人机

private slots:
    void on_pvp_clicked();

    void on_pve_clicked();

    void reshow();

signals:
    void showmain();

private:
    Ui::showpage *ui;
};

#endif // SHOWPAGE_H
