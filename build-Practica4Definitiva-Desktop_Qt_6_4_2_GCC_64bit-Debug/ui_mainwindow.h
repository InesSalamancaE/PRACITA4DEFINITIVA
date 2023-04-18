/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *tiempo1;
    QLineEdit *tiempo1_2;
    QLineEdit *tiempo1_3;
    QLineEdit *tiempo1_4;
    QLineEdit *tiempo1_5;
    QLineEdit *tiempo1_6;
    QLineEdit *tiempo1_7;
    QLineEdit *tiempo1_8;
    QLineEdit *tiempo1_9;
    QLabel *labelTiempo1;
    QLabel *labelTiempo1_2;
    QLabel *labelTiempo1_3;
    QLabel *labelTiempo1_4;
    QPushButton *botonEjecutar;
    QPushButton *botonEjecutar_2;
    QPushButton *botonEjecutar_3;
    QPushButton *botonEjecutar_4;
    QLabel *labelTiempo1_5;
    QLabel *labelTiempo1_6;
    QLabel *labelTiempo1_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1099, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tiempo1 = new QLineEdit(centralwidget);
        tiempo1->setObjectName("tiempo1");
        tiempo1->setGeometry(QRect(170, 60, 151, 25));
        tiempo1_2 = new QLineEdit(centralwidget);
        tiempo1_2->setObjectName("tiempo1_2");
        tiempo1_2->setGeometry(QRect(380, 60, 151, 25));
        tiempo1_3 = new QLineEdit(centralwidget);
        tiempo1_3->setObjectName("tiempo1_3");
        tiempo1_3->setGeometry(QRect(610, 60, 151, 25));
        tiempo1_4 = new QLineEdit(centralwidget);
        tiempo1_4->setObjectName("tiempo1_4");
        tiempo1_4->setGeometry(QRect(170, 130, 151, 25));
        tiempo1_5 = new QLineEdit(centralwidget);
        tiempo1_5->setObjectName("tiempo1_5");
        tiempo1_5->setGeometry(QRect(380, 130, 151, 25));
        tiempo1_6 = new QLineEdit(centralwidget);
        tiempo1_6->setObjectName("tiempo1_6");
        tiempo1_6->setGeometry(QRect(610, 130, 151, 25));
        tiempo1_7 = new QLineEdit(centralwidget);
        tiempo1_7->setObjectName("tiempo1_7");
        tiempo1_7->setGeometry(QRect(170, 340, 151, 25));
        tiempo1_8 = new QLineEdit(centralwidget);
        tiempo1_8->setObjectName("tiempo1_8");
        tiempo1_8->setGeometry(QRect(380, 340, 151, 25));
        tiempo1_9 = new QLineEdit(centralwidget);
        tiempo1_9->setObjectName("tiempo1_9");
        tiempo1_9->setGeometry(QRect(610, 340, 151, 25));
        labelTiempo1 = new QLabel(centralwidget);
        labelTiempo1->setObjectName("labelTiempo1");
        labelTiempo1->setGeometry(QRect(40, 60, 121, 21));
        QFont font;
        font.setPointSize(14);
        labelTiempo1->setFont(font);
        labelTiempo1_2 = new QLabel(centralwidget);
        labelTiempo1_2->setObjectName("labelTiempo1_2");
        labelTiempo1_2->setGeometry(QRect(40, 130, 121, 21));
        labelTiempo1_2->setFont(font);
        labelTiempo1_3 = new QLabel(centralwidget);
        labelTiempo1_3->setObjectName("labelTiempo1_3");
        labelTiempo1_3->setGeometry(QRect(40, 230, 121, 21));
        labelTiempo1_3->setFont(font);
        labelTiempo1_4 = new QLabel(centralwidget);
        labelTiempo1_4->setObjectName("labelTiempo1_4");
        labelTiempo1_4->setGeometry(QRect(40, 340, 121, 21));
        labelTiempo1_4->setFont(font);
        botonEjecutar = new QPushButton(centralwidget);
        botonEjecutar->setObjectName("botonEjecutar");
        botonEjecutar->setGeometry(QRect(600, 220, 61, 51));
        botonEjecutar_2 = new QPushButton(centralwidget);
        botonEjecutar_2->setObjectName("botonEjecutar_2");
        botonEjecutar_2->setGeometry(QRect(450, 220, 61, 51));
        botonEjecutar_3 = new QPushButton(centralwidget);
        botonEjecutar_3->setObjectName("botonEjecutar_3");
        botonEjecutar_3->setGeometry(QRect(330, 220, 61, 51));
        botonEjecutar_4 = new QPushButton(centralwidget);
        botonEjecutar_4->setObjectName("botonEjecutar_4");
        botonEjecutar_4->setGeometry(QRect(210, 220, 61, 51));
        labelTiempo1_5 = new QLabel(centralwidget);
        labelTiempo1_5->setObjectName("labelTiempo1_5");
        labelTiempo1_5->setGeometry(QRect(210, 20, 121, 21));
        labelTiempo1_5->setFont(font);
        labelTiempo1_6 = new QLabel(centralwidget);
        labelTiempo1_6->setObjectName("labelTiempo1_6");
        labelTiempo1_6->setGeometry(QRect(410, 20, 121, 21));
        labelTiempo1_6->setFont(font);
        labelTiempo1_7 = new QLabel(centralwidget);
        labelTiempo1_7->setObjectName("labelTiempo1_7");
        labelTiempo1_7->setGeometry(QRect(650, 20, 121, 21));
        labelTiempo1_7->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1099, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        labelTiempo1->setText(QCoreApplication::translate("MainWindow", "Operando 1", nullptr));
        labelTiempo1_2->setText(QCoreApplication::translate("MainWindow", "Operando 2", nullptr));
        labelTiempo1_3->setText(QCoreApplication::translate("MainWindow", "Operaci\303\263n", nullptr));
        labelTiempo1_4->setText(QCoreApplication::translate("MainWindow", "Resultado", nullptr));
        botonEjecutar->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        botonEjecutar_2->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        botonEjecutar_3->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        botonEjecutar_4->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        labelTiempo1_5->setText(QCoreApplication::translate("MainWindow", "REAL", nullptr));
        labelTiempo1_6->setText(QCoreApplication::translate("MainWindow", "IEEE 754", nullptr));
        labelTiempo1_7->setText(QCoreApplication::translate("MainWindow", "HEX", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
