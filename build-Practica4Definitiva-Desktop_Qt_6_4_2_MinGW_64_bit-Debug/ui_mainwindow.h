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
    QLineEdit *num1;
    QLineEdit *ieee1;
    QLineEdit *hexa1;
    QLineEdit *num2;
    QLineEdit *ieee2;
    QLineEdit *hexa2;
    QLineEdit *decimalResultado;
    QLineEdit *ieeeResultado;
    QLineEdit *hexaResultado;
    QLabel *labelTiempo1;
    QLabel *labelTiempo1_2;
    QLabel *labelTiempo1_3;
    QLabel *labelTiempo1_4;
    QPushButton *botonEquals;
    QPushButton *botonDivision;
    QPushButton *botonMultiplicacion;
    QPushButton *botonSuma;
    QLabel *labelTiempo1_5;
    QLabel *labelTiempo1_6;
    QLabel *labelTiempo1_7;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(1099, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        num1 = new QLineEdit(centralwidget);
        num1->setObjectName("num1");
        num1->setGeometry(QRect(150, 60, 151, 25));
        ieee1 = new QLineEdit(centralwidget);
        ieee1->setObjectName("ieee1");
        ieee1->setEnabled(true);
        ieee1->setGeometry(QRect(320, 60, 311, 25));
        ieee1->setReadOnly(true);
        ieee1->setClearButtonEnabled(false);
        hexa1 = new QLineEdit(centralwidget);
        hexa1->setObjectName("hexa1");
        hexa1->setGeometry(QRect(650, 60, 151, 25));
        hexa1->setReadOnly(true);
        num2 = new QLineEdit(centralwidget);
        num2->setObjectName("num2");
        num2->setGeometry(QRect(150, 130, 151, 25));
        ieee2 = new QLineEdit(centralwidget);
        ieee2->setObjectName("ieee2");
        ieee2->setGeometry(QRect(320, 130, 311, 25));
        ieee2->setReadOnly(true);
        hexa2 = new QLineEdit(centralwidget);
        hexa2->setObjectName("hexa2");
        hexa2->setGeometry(QRect(650, 130, 151, 25));
        hexa2->setReadOnly(true);
        decimalResultado = new QLineEdit(centralwidget);
        decimalResultado->setObjectName("decimalResultado");
        decimalResultado->setGeometry(QRect(150, 340, 151, 25));
        decimalResultado->setReadOnly(true);
        ieeeResultado = new QLineEdit(centralwidget);
        ieeeResultado->setObjectName("ieeeResultado");
        ieeeResultado->setGeometry(QRect(320, 340, 311, 25));
        ieeeResultado->setReadOnly(true);
        hexaResultado = new QLineEdit(centralwidget);
        hexaResultado->setObjectName("hexaResultado");
        hexaResultado->setGeometry(QRect(650, 340, 151, 25));
        hexaResultado->setReadOnly(true);
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
        botonEquals = new QPushButton(centralwidget);
        botonEquals->setObjectName("botonEquals");
        botonEquals->setGeometry(QRect(700, 220, 61, 51));
        botonDivision = new QPushButton(centralwidget);
        botonDivision->setObjectName("botonDivision");
        botonDivision->setGeometry(QRect(530, 220, 61, 51));
        botonMultiplicacion = new QPushButton(centralwidget);
        botonMultiplicacion->setObjectName("botonMultiplicacion");
        botonMultiplicacion->setGeometry(QRect(390, 220, 61, 51));
        botonSuma = new QPushButton(centralwidget);
        botonSuma->setObjectName("botonSuma");
        botonSuma->setGeometry(QRect(180, 220, 61, 51));
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
        labelTiempo1_7->setGeometry(QRect(710, 20, 61, 21));
        labelTiempo1_7->setFont(font);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1099, 24));
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
        botonEquals->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        botonDivision->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        botonMultiplicacion->setText(QCoreApplication::translate("MainWindow", "*", nullptr));
        botonSuma->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
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
