#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <alu.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    union floatNum {

            float flo;
            struct{
                unsigned int mantisa : 23;
                unsigned int exponente : 8;
                unsigned int signo : 1;
            }raw;
        };

    floatNum valor1;
    floatNum valor2;

private slots:


    void on_botonSuma_clicked();

    void on_botonEquals_clicked();

    void on_botonMultiplicacion_clicked();

    void on_botonDivision_clicked();

private:
    Ui::MainWindow *ui;
    int numADec;
    int numBDec;
    int numResDec;

    int numABin;
    int numBBin;
    int numResBin;

    QString numAHex;
    QString numBHex;
    QString numResHex;
};
#endif // MAINWINDOW_H
