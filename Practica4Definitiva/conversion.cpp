#include "conversion.h"
#include <stdio.h>
#include <unistd.h>
#include <iostream>

using namespace std;

conversion::conversion()
{

}

union Code {

    struct{
        unsigned int partFrac : 23;
        unsigned int expo : 8;
        unsigned int sign : 1;
    }bitfield;

    float numero;
    unsigned int numerox;
};

/*int main (void){
    int tipo;
    do{
    printf("\n");
    printf("=====================================\nIntroduzca una operacion a realizar:\n1) Convertir real a IEEE 754.\n2) Convertir IEEE 754 a real.\n3) Convertir un número predeterminado a IEEE 754. \n0) SALIR\n=====================================\n");
    scanf("%d",&tipo);
    switch(tipo){
        case 1:
            floattoIEE ();
        break;
        case 2:
            IEEtofloat ();
        break;
        case 3:
            floattoIEE2 ();
        break;
        case 4:
            IEEtofloat2 ();
        break;
        default:
            if ((tipo >4) || (tipo<0)){
                printf ("Error. Operación incorrecta.\n");
            }
        }
    } while (tipo!=0);
}*/

void conversion::floattoIEE (float numAconvertir){

    //mirar si funciona!!!! :)

    union Code a;
    a.numero = numAconvertir;
    /*printf ("Introduce un número: ");
    scanf ("%f", &a.numero);
    printf("Signo: %u \n",a.bitfield.sign);
    printf("Exponente: %u \n",a.bitfield.expo);
    printf("Parte Fraccionaria : %u \n", a.bitfield.partFrac);*/

    this->signo = a.bitfield.sign;
    this->exponente = a.bitfield.expo;
    this->fraccionaria = a.bitfield.partFrac;

    std::string numeroString = std::to_string(signo) + std::to_string(exponente) + std::to_string(fraccionaria);
    this->numIEEE = std::stof(numeroString);


}

void conversion::floattoIEE2 (){

    union Code a;
    a.numero=2.1;
    printf("Numero a imprimir: %f \n", a.numero);
    //printf("Numero unsigned: %u \n", a.numerox);
    printf("Signo: %u \n",a.bitfield.sign);
    printf("Exponente: %u \n",a.bitfield.expo);
    printf("Parte Fraccionaria : %u \n", a.bitfield.partFrac);

}

void conversion::IEEtofloat (){

    union Code a;
    int b, c, d;
    printf ("Introduce el signo: ");
    scanf ("%d", &b);
    printf ("Introduce el exponente: ");
    scanf ("%d", &c);
    printf ("Introduce la mantisa: ");
    scanf ("%d", &d);

    a.bitfield.sign = b;
    a.bitfield.expo = c;
    a.bitfield.partFrac = d;

    printf("El número pasado a real es: %f \n", a.numero);
}

void conversion::IEEtofloat2 (){

    union Code a;

    a.bitfield.partFrac = 4718592;
    a.bitfield.expo = 131;
    a.bitfield.sign = 0;
    printf("El número es: %f \n", a.numero);

}
