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

    floatNum numA;
    floatNum numB;

private slots:


    void on_botonSuma_clicked();

    void on_botonEquals_clicked();

    void on_botonMultiplicacion_clicked();

    void on_botonDivision_clicked();

    QString decimalABinario(int numero, int longitud);

    float binarioADecimal(QString binario);

    QString binarioAHexadecimal(QString binario);

    QString numIEEE(MainWindow::floatNum var);

    QString numIEEEJunto(MainWindow::floatNum var);

    QString quitarEspacios(QString ieeeEspacio);

    void on_botonClear_clicked();

private:
    Ui::MainWindow *ui;

    QString numResDec;

    QString numABin;
    QString numBBin;
    QString numResBin;

    QString numAHex;
    QString numBHex;
    QString numResHex;

    QString signoA;
    QString exponenteA;
    QString mantisaA;
    QString signoB;
    QString exponenteB;
    QString mantisaB;
};
#endif // MAINWINDOW_H
