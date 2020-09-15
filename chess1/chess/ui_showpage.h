/********************************************************************************
** Form generated from reading UI file 'showpage.ui'
**
** Created by: Qt User Interface Compiler version 5.9.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOWPAGE_H
#define UI_SHOWPAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_showpage
{
public:
    QPushButton *pvp;
    QPushButton *pve;
    QLabel *label;
    QWidget *widget;
    QPushButton *pushButton;
    QPushButton *eve;

    void setupUi(QDialog *showpage)
    {
        if (showpage->objectName().isEmpty())
            showpage->setObjectName(QStringLiteral("showpage"));
        showpage->resize(860, 860);
        showpage->setStyleSheet(QStringLiteral(""));
        pvp = new QPushButton(showpage);
        pvp->setObjectName(QStringLiteral("pvp"));
        pvp->setGeometry(QRect(319, 530, 222, 102));
        pvp->setStyleSheet(QStringLiteral(""));
        pvp->setCheckable(true);
        pvp->setAutoExclusive(true);
        pve = new QPushButton(showpage);
        pve->setObjectName(QStringLiteral("pve"));
        pve->setGeometry(QRect(319, 680, 222, 102));
        pve->setStyleSheet(QString::fromUtf8("font: 28pt \"\346\245\267\344\275\223\";"));
        label = new QLabel(showpage);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(250, 30, 360, 171));
        label->setStyleSheet(QString::fromUtf8("font: 72pt \"\351\232\266\344\271\246\";"));
        widget = new QWidget(showpage);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(-1, -1, 871, 871));
        widget->setStyleSheet(QStringLiteral("border-image: url(:/qi.jpg);"));
        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(90, 150, 31, 31));
        pushButton->setStyleSheet(QStringLiteral("border-right-color: qradialgradient(spread:pad, cx:0.5, cy:0.5, radius:0.5, fx:0.5, fy:0.5, stop:0 rgba(0, 0, 0, 0), stop:0.52 rgba(0, 0, 0, 0), stop:0.565 rgba(82, 121, 76, 33), stop:0.65 rgba(159, 235, 148, 64), stop:0.721925 rgba(255, 238, 150, 129), stop:0.77 rgba(255, 128, 128, 204), stop:0.89 rgba(191, 128, 255, 64), stop:1 rgba(0, 0, 0, 0));"));
        eve = new QPushButton(widget);
        eve->setObjectName(QStringLiteral("eve"));
        eve->setGeometry(QRect(610, 600, 93, 28));
        eve->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\345\275\251\344\272\221\";"));
        widget->raise();
        pvp->raise();
        pve->raise();
        label->raise();

        retranslateUi(showpage);

        QMetaObject::connectSlotsByName(showpage);
    } // setupUi

    void retranslateUi(QDialog *showpage)
    {
        showpage->setWindowTitle(QApplication::translate("showpage", "Dialog", Q_NULLPTR));
        pvp->setText(QString());
        pve->setText(QString());
        label->setText(QApplication::translate("showpage", "\345\205\255\345\255\220\346\243\213", Q_NULLPTR));
        pushButton->setText(QApplication::translate("showpage", "?", Q_NULLPTR));
        eve->setText(QApplication::translate("showpage", "\346\234\272\346\234\272\345\257\271\346\210\230", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class showpage: public Ui_showpage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOWPAGE_H
