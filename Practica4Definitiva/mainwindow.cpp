
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
    int numADec = ui->num1->text().toInt();
    int numBDec = ui->num2->text().toInt();
    int numResDec = numADec+numBDec;

    //Se pasan los valores decimales a binario ieee754 y se muestran

    ui->ieee1->setText(numABin);
    ui->ieee2->setText(numBBin);
    //Se suman los binarios
    alu.suma(numABin, numBBin);

    //Se pasan los valores decimales a hexadecimal y se muestran

    ui->hexa1->setText(numAHex);
    ui->hexa2->setText(numBHex);
    //Se suman los hexadecimales

}

void MainWindow::on_botonMultiplicacion_clicked()
{
    //Se multiplican los valores en decimal
    int numADec = ui->num1->text().toInt();
    int numBDec = ui->num2->text().toInt();
    int numResDec = numADec*numBDec;

    //Se pasan los valores decimales a binario ieee754 y se muestran

    ui->ieee1->setText(numABin);
    ui->ieee2->setText(numBBin);
    //Se multiplican los binarios
    alu.multiplicacion();

    //Se pasan los valores decimales a hexadecimal y se muestran

    ui->hexa1->setText(numAHex);
    ui->hexa2->setText(numBHex);
    //Se multiplican los hexadecimales


}


void MainWindow::on_botonDivision_clicked()
{
    //Se dividen los valores en decimal
    int numADec = ui->num1->text().toInt();
    int numBDec = ui->num2->text().toInt();
    int numResDec = numADec/numBDec;

    //Se pasan los valores decimales a binario ieee754 y se muestran

    ui->ieee1->setText(numABin);
    ui->ieee2->setText(numBBin);
    //Se dividen los binarios
    alu.division();

    //Se pasan los valores decimales a hexadecimal y se muestran

    ui->hexa1->setText(numAHex);
    ui->hexa2->setText(numBHex);
    //Se dividen los hexadecimales


}

void MainWindow::on_botonEquals_clicked()
{
    //Se muestra el resultado de la operación que se haya seleccionado
    ui->decimalResultado->setText(numResDec);
    ui->hexaResultado->setText(numResHex);
    ui->ieeeResultado->setText(numResBin);
}
