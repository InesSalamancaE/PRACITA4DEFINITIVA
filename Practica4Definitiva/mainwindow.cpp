
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "alu.h"
#include <iostream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <cmath>
#include <bitset>

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
    alu alu;
    //Se cogen los valores de decimal por pantalla
    numA.flo = ui->num1->text().toFloat();
    numB.flo = ui->num2->text().toFloat();

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));

    //Se pasan los valores binarios a hexadecimal y se muestran
    ui->hexa1->setText(binarioAHexadecimal(numIEEEJunto(numA)));
    ui->hexa2->setText(binarioAHexadecimal(numIEEEJunto(numB)));

    //Se almacenan en las variables los ieee separados en signo, exponente y mantisa
    signoA = QString::number(numA.raw.signo);
    exponenteA = decimalABinario(numA.raw.exponente, 8);
    mantisaA = decimalABinario(numA.raw.mantisa, 23);
    mantisaA.prepend("1");

    signoB = QString::number(numB.raw.signo);
    exponenteB = decimalABinario(numB.raw.exponente, 8);
    mantisaB = decimalABinario(numB.raw.mantisa, 23);
    mantisaB.prepend("1");

    //Se suman los binarios
    numResBin=alu.suma(signoA, exponenteA, mantisaA, signoB, exponenteB, mantisaB);

    //------------ Si funciona, pero como la suma da cosas raras, peta el programa, cuando de bien, descomentamos !!!!!!!!!!!!!!!!
    //Se pasa el resultado de suma binaria a decimal
    //numResDec = binarioADecimal(quitarEspacios(numResBin));
    numResDec = numA.flo+numB.flo;

    //Se pasa el resultado de suma binaria a hexadecimal
    //numResHex=binarioAHexadecimal(quitarEspacios(numResBin));

}

void MainWindow::on_botonMultiplicacion_clicked()
{
    alu alu;
    //Se multiplican los valores en decimal
    numA.flo = ui->num1->text().toFloat();
    numB.flo = ui->num2->text().toFloat();

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));

    //Se pasan los valores binarios a hexadecimal y se muestran
    ui->hexa1->setText(binarioAHexadecimal(numIEEEJunto(numA)));
    ui->hexa2->setText(binarioAHexadecimal(numIEEEJunto(numB)));

    //Se almacenan en las variables los ieee separados en signo, exponente y mantisa
    signoA = QString::number(numA.raw.signo);
    exponenteA = decimalABinario(numA.raw.exponente, 8);
    mantisaA = decimalABinario(numA.raw.mantisa, 23);
    mantisaA.prepend("1");

    signoB = QString::number(numB.raw.signo);
    exponenteB = decimalABinario(numB.raw.exponente, 8);
    mantisaB = decimalABinario(numB.raw.mantisa, 23);
    mantisaB.prepend("1");

    //Se multiplican los binarios
    //numResBin=alu.multiplicacion(signoA, exponenteA, mantisaA, signoB, exponenteB, mantisaB);

    //Se pasa el resultado de multiplicación binaria a decimal
    //numResDec=binarioADecimal(quitarEspacios(numResBin));
    numResDec = numA.flo*numB.flo;

    //Se pasa el resultado de multiplicación binaria a hexadecimal
    //numResHex=binarioAHexadecimal(quitarEspacios(numResBin));

}


void MainWindow::on_botonDivision_clicked()
{
    alu alu;
    //Se dividen los valores en decimal
    numA.flo = ui->num1->text().toFloat();
    numB.flo = ui->num2->text().toFloat();

    //Se pasan los valores decimales a binario ieee754 y se muestran
    ui->ieee1->setText(numIEEE(numA));
    ui->ieee2->setText(numIEEE(numB));

    //Se pasan los valores binarios a hexadecimal y se muestran
    ui->hexa1->setText(binarioAHexadecimal(numIEEEJunto(numA)));
    ui->hexa2->setText(binarioAHexadecimal(numIEEEJunto(numB)));

    //Se almacenan en las variables los ieee separados en signo, exponente y mantisa
    signoA = QString::number(numA.raw.signo);
    exponenteA = decimalABinario(numA.raw.exponente, 8);
    mantisaA = decimalABinario(numA.raw.mantisa, 23);
    mantisaA.prepend("1");

    signoB = QString::number(numB.raw.signo);
    exponenteB = decimalABinario(numB.raw.exponente, 8);
    mantisaB = decimalABinario(numB.raw.mantisa, 23);
    mantisaB.prepend("1");

    //Se dividen los binarios
    //numResBin=alu.division(signoA, exponenteA, mantisaA, signoB, exponenteB, mantisaB);


    //Se pasa el resultado de división binaria a decimal
    //numResDec=binarioADecimal(quitarEspacios(numResBin));
    numResDec = numA.flo/numB.flo;

    //Se pasa el resultado de división binaria a hexadecimal
    //numResHex=binarioAHexadecimal(quitarEspacios(numResBin));

}

void MainWindow::on_botonEquals_clicked()
{
    //Se muestra el resultado de la operación que se haya seleccionado
    ui->decimalResultado->setText(QString::number(numResDec));
    ui->hexaResultado->setText(numResHex);
    ui->ieeeResultado->setText(numResBin);
}

QString MainWindow::decimalABinario(int numero,int longitud){
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

QString MainWindow::binarioADecimal(QString binario){
    QString decimal=0;

    /*
    QString binarioString = binario;
    int longitud = binarioString.length();
    int contador = longitud-1;
    for(int i=0; i<longitud; i++){
        decimal=decimal+(binarioString[i].digitValue()*2^contador);
        contador--;
    }
    */

    return decimal;
}

QString MainWindow::binarioAHexadecimal(QString binario){
    // Convertimos el QString que representa el número binario en un entero de tipo unsigned long long
    unsigned long long numeroEntero = std::bitset<64>(binario.toStdString()).to_ullong();

    // Utilizamos la función QString::number() para convertir el número entero en hexadecimal y lo almacenamos en un QString
    QString numeroHexadecimal = QString::number(numeroEntero, 16);
    numeroHexadecimal.prepend("0x");
    // Devolvemos el QString que representa el número hexadecimal
    return numeroHexadecimal;
}

QString MainWindow::numIEEE(floatNum numero)
{
    QString answer;

    answer=QString::number(numero.raw.signo)+" "+decimalABinario(numero.raw.exponente, 8)+" "+decimalABinario(numero.raw.mantisa, 23);
    return answer;
}


QString MainWindow::numIEEEJunto(floatNum numero)
{
    QString answer;

    answer=QString::number(numero.raw.signo)+decimalABinario(numero.raw.exponente, 8)+decimalABinario(numero.raw.mantisa, 23);
    return answer;
}

QString MainWindow::quitarEspacios(QString ieeeEspacios){
    ieeeEspacios.remove(1,1);
    ieeeEspacios.remove(9,1);

    return ieeeEspacios;
}
