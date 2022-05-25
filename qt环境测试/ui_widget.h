/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLabel *LabDemo;
    QPushButton *btnClose;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(680, 624);
        QFont font;
        font.setFamily(QString::fromUtf8("ADMUI3Lg"));
        font.setBold(true);
        font.setUnderline(true);
        font.setWeight(75);
        Widget->setFont(font);
        LabDemo = new QLabel(Widget);
        LabDemo->setObjectName(QString::fromUtf8("LabDemo"));
        LabDemo->setGeometry(QRect(200, 120, 251, 111));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setUnderline(true);
        font1.setWeight(75);
        LabDemo->setFont(font1);
        btnClose = new QPushButton(Widget);
        btnClose->setObjectName(QString::fromUtf8("btnClose"));
        btnClose->setGeometry(QRect(220, 270, 141, 51));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font2.setPointSize(10);
        font2.setBold(false);
        font2.setUnderline(false);
        font2.setWeight(50);
        btnClose->setFont(font2);

        retranslateUi(Widget);
        QObject::connect(btnClose, SIGNAL(clicked()), Widget, SLOT(close()));

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Form", nullptr));
        LabDemo->setText(QCoreApplication::translate("Widget", "yunxingluoyun", nullptr));
        btnClose->setText(QCoreApplication::translate("Widget", "\345\205\263\351\227\255", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
