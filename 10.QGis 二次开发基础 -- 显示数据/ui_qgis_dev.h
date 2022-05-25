/********************************************************************************
** Form generated from reading UI file 'qgis_devAraFpE.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef QGIS_DEVARAFPE_H
#define QGIS_DEVARAFPE_H

//#define M_PI    3.14159265358979323846
//#define M_PI_2  1.57079632679489661923
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_Vector;
    QAction *actionAdd_Raster;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuFiles;
    QMenu *menuVector;
    QMenu *menuRaster;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 600);
        actionAdd_Vector = new QAction(MainWindow);
        actionAdd_Vector->setObjectName(QString::fromUtf8("actionAdd_Vector"));
        actionAdd_Raster = new QAction(MainWindow);
        actionAdd_Raster->setObjectName(QString::fromUtf8("actionAdd_Raster"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        menubar->setDefaultUp(false);
        menuFiles = new QMenu(menubar);
        menuFiles->setObjectName(QString::fromUtf8("menuFiles"));
        menuVector = new QMenu(menubar);
        menuVector->setObjectName(QString::fromUtf8("menuVector"));
        menuRaster = new QMenu(menubar);
        menuRaster->setObjectName(QString::fromUtf8("menuRaster"));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFiles->menuAction());
        menubar->addAction(menuVector->menuAction());
        menubar->addAction(menuRaster->menuAction());
        menuVector->addAction(actionAdd_Vector);
        menuRaster->addAction(actionAdd_Raster);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "qgis_dev", nullptr));
        actionAdd_Vector->setText(QCoreApplication::translate("MainWindow", "Add Vector ", nullptr));
        actionAdd_Raster->setText(QCoreApplication::translate("MainWindow", "Add Raster", nullptr));
        menuFiles->setTitle(QCoreApplication::translate("MainWindow", "Files", nullptr));
        menuVector->setTitle(QCoreApplication::translate("MainWindow", "Vector", nullptr));
        menuRaster->setTitle(QCoreApplication::translate("MainWindow", "Raster", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // QGIS_DEVARAFPE_H
