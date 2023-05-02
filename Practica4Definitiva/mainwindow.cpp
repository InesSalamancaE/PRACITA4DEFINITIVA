
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
    //Se suman los valores en decimal //a
    numA.flo = ui->num1->text().toFloat();
    numB.flo = ui->num2->text().toFloat();
    numResDec = numA.flo+numB.flo;

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));

    //Se almacenan en las variables los ieee separados en signo, exponente y mantisa
    signoA = QString::number(numA.raw.signo);
    exponenteA = pasarBinario(numA.raw.exponente, 8);
    mantisaA = pasarBinario(numA.raw.mantisa, 23);
    mantisaA.prepend("1");

    signoB = QString::number(numB.raw.signo);
    exponenteB = pasarBinario(numB.raw.exponente, 8);
    mantisaB = pasarBinario(numB.raw.mantisa, 23);
    mantisaB.prepend("1");

    //Se suman los binarios
    //alu.suma(signoA, exponenteA, mantisaA, signoB, exponenteB, mantisaB);

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
    numResDec = numA.flo*numB.flo;

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));

    //Se almacenan en las variables los ieee separados en signo, exponente y mantisa
    signoA = QString::number(numA.raw.signo);
    exponenteA = pasarBinario(numA.raw.exponente, 8);
    mantisaA = pasarBinario(numA.raw.mantisa, 23);
    mantisaA.prepend("1");

    signoB = QString::number(numB.raw.signo);
    exponenteB = pasarBinario(numB.raw.exponente, 8);
    mantisaB = pasarBinario(numB.raw.mantisa, 23);
    mantisaB.prepend("1");

    //Se multiplican los binarios
    //alu.multiplicacion(signoA, exponenteA, mantisaA, signoB, exponenteB, mantisaB);

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
    numResDec = numA.flo/numB.flo;

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));

    //Se almacenan en las variables los ieee separados en signo, exponente y mantisa
    signoA = QString::number(numA.raw.signo);
    exponenteA = pasarBinario(numA.raw.exponente, 8);
    mantisaA = pasarBinario(numA.raw.mantisa, 23);
    mantisaA.prepend("1");

    signoB = QString::number(numB.raw.signo);
    exponenteB = pasarBinario(numB.raw.exponente, 8);
    mantisaB = pasarBinario(numB.raw.mantisa, 23);
    mantisaB.prepend("1");

    //Se dividen los binarios
    //alu.division(signoA, exponenteA, mantisaA, signoB, exponenteB, mantisaB);

    //Se pasan los valores decimales a hexadecimal y se muestran
    ui->hexa1->setText(pasarHexadecimal(numA.flo));
    ui->hexa2->setText(pasarHexadecimal(numB.flo));
    //Se dividen los hexadecimales


}

void MainWindow::on_botonEquals_clicked()
{
    //Se muestra el resultado de la operación que se haya seleccionado
    ui->decimalResultado->setText(QString::number(numResDec));
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
    QString answer=QString::number(numero);
    return answer;
}

QString MainWindow::numIEEE(floatNum numero)
{
    QString answer;

    answer=QString::number(numero.raw.signo)+" "+pasarBinario(numero.raw.exponente, 8)+" "+pasarBinario(numero.raw.mantisa, 23);
    return answer;
}
