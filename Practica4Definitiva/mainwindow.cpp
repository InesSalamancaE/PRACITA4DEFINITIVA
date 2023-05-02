
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_botonSuma_clicked()
{
    //Se suman los valores en decimal
    numA.flo = ui->num1->text().toFloat();
    numB.flo = ui->num2->text().toFloat();
    float numResDec = numA.flo+numB.flo;

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));
    //Se suman los binarios
    //alu.suma(numABin, numBBin); //pasar bien los atrib

    //Se pasan los valores decimales a hexadecimal y se muestran
    ui->hexa1->setText(pasarHexadecimal(numA.flo));
    ui->hexa2->setText(pasarHexadecimal(numB.flo));
    //Se suman los hexadecimales

}

void MainWindow::on_botonMultiplicacion_clicked()
{
    //Se multiplican los valores en decimal
    numA.flo = ui->num1->text().toFloat();
    numB.flo = ui->num2->text().toFloat();
    float numResDec = numA.flo*numB.flo;

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));
    //Se multiplican los binarios
    //alu.multiplicacion();

    //Se pasan los valores decimales a hexadecimal y se muestran
    ui->hexa1->setText(pasarHexadecimal(numA.flo));
    ui->hexa2->setText(pasarHexadecimal(numB.flo));
    //Se multiplican los hexadecimales


}


void MainWindow::on_botonDivision_clicked()
{
    //Se dividen los valores en decimal
    numA.flo = ui->num1->text().toFloat();
    numB.flo = ui->num2->text().toFloat();
    float numResDec = numA.flo/numB.flo;

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));
    //Se dividen los binarios
    //alu.division();

    //Se pasan los valores decimales a hexadecimal y se muestran
    ui->hexa1->setText(pasarHexadecimal(numA.flo));
    ui->hexa2->setText(pasarHexadecimal(numB.flo));
    //Se dividen los hexadecimales


}

void MainWindow::on_botonEquals_clicked()
{
    //Se muestra el resultado de la operación que se haya seleccionado
    ui->decimalResultado->setText(numResDec);
    ui->hexaResultado->setText(numResHex);
    ui->ieeeResultado->setText(numResBin);
}

QString MainWindow::pasarBinario(int numero,int longitud){
    QString binario;
    while (numero > 0) {
        binario.prepend(QString::number(numero%2));
        numero = numero / 2;
    }

    while (binario.length() < longitud) {
        binario.prepend("0");
    }

    return binario;
}

QString MainWindow::pasarHexadecimal(float numero){

}
QString MainWindow::numIEEE(floatNum numero)
{
    QString answer;

    answer=QString::number(numero.raw.signo)+" "+pasarBinario(numero.raw.exponente, 8)+" "+pasarBinario(numero.raw.mantisa, 23);
    return answer;
}
