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


private slots:
    void on_pvp_clicked();

    void on_pve_clicked();

    void reshow();

signals:
    void showmain1();
    void showmain0();

private:
    Ui::showpage *ui;
};

#endif // SHOWPAGE_H
