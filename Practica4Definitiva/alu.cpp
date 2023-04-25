#include "alu.h"
#include<bitset>

using std::bitset;

alu::alu()
{

}

//Método para sumar dos numeros binarios (Pasamos siempre dos nums con el mismo numero de bist)
QString alu::sumaBinario(int Numa, int Numb){

    QString a = QString::number(Numa);
    QString b = QString::number(Numb);
    QString solucion;
    bool acarreo = false;

    for(int i=a.length()-1; i<0; i--){

        if(a[i]=='0' && b[i]=='0'){

            if(acarreo == true){

                solucion = '1' + solucion;
                acarreo = false;
            }
            else{
               solucion = '0' + solucion;
            }

        }
        else if((a[i]=='1' && b[i]=='0') || (a[i]=='0' && b[i]=='1')){

            if(acarreo == true){

                solucion = '0' + solucion;

            }
            else{
               solucion = '1' + solucion;
            }

        }
        else{

            acarreo = true;
            solucion = '0' + solucion;
        }
    }

    return solucion;
}



QString alu::suma(QString signoA, QString exponenteA, QString mantisaA, QString signoB, QString exponenteB, QString mantisaB){

    //Pasamos a int los parámetros del método
    int signoAint = signoA.toInt();
    int exponenteAint = exponenteA.toInt();
    int mantisaAint = mantisaA.toInt();
    int signoBint = signoB.toInt();
    int exponenteBint = exponenteB.toInt();
    int mantisaBint = mantisaB.toInt();

    //1.Inicialización de variables
    int P = 0;
    int g = 0;
    int r = 0;
    int st = 0;
    int n = 24;
    bool Operandos_intercambiados = false;
    bool Complemento_P = false;

    //2.Siempre hay que sumar NumGrando + NumPequeño.
    if(exponenteAint<exponenteBint){

        int signoAuxiliar = signoAint;
        int exponenteAuxiliar = exponenteAint;
        int mantisaAuxiliar = mantisaAint;
        signoAint = signoBint;
        exponenteAint = exponenteBint;
        mantisaAint = mantisaBint;
        signoBint = signoAuxiliar;
        exponenteBint = exponenteAuxiliar;
        mantisaBint = mantisaAuxiliar;

        QString signoAuxiliarString = signoA;
        QString exponenteAuxiliarString = exponenteA;
        QString mantisaAuxiliarString = mantisaA;
        signoA = signoB;
        exponenteA = exponenteB;
        mantisaA = mantisaB;
        signoB = signoAuxiliarString;
        exponenteB = exponenteAuxiliarString;
        mantisaB = mantisaAuxiliarString;

        Operandos_intercambiados = true;
    }

    //3.
    int exponenteSumaInt = exponenteAint;
    QString exponenteSuma = exponenteA;

 //---------------------------------------------COMPLEMENTO A 2: PODEMOS PASARLO A METODO EN CASO NECESARIO--------------------------------
    //ea - eb: Calculamos el complemento a 2 de eb y se lo sumamos a ea
    QString ebComplemento = sumaBinario(exponenteBint, 00000001);    //Sumamos 1 a exponente de b
    for(int i=0; i<ebComplemento.length(); i++){ //cambiamos los 0s por 1s y los 1s por 0s

        if(ebComplemento[i]=='0'){
            ebComplemento[i]=='1';
        }
        else{
            ebComplemento[i]=='0';
        }
    } //Aqui acaba el calculo del complemento a 2 de eb

    int ebComplementoInt = ebComplemento.toInt();
    QString d = sumaBinario(exponenteAint, ebComplementoInt);

    //4.
    if(signoAint!=signoBint){   //Si los signos son distintos, la mantisa de b pasa a ser el complemento

        QString mbComplemento = sumaBinario(mantisaBint, 000000000000000000000001);    //Sumamos 1 a exponente de b
        for(int i=0; i<mbComplemento.length(); i++){ //cambiamos los 0s por 1s y los 1s por 0s

            if(mbComplemento[i]=='0'){
                mbComplemento[i]=='1';
            }
            else{
                mbComplemento[i]=='0';
            }
        } //Aqui acaba el calculo del complemento a 2 de eb

        mantisaB = mbComplemento;
        mantisaBint = mantisaB.toInt();

    }



}
