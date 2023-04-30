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

    //4.Si los signos son distintos, la mantisa de b pasa a ser el complemento
    if(signoAint!=signoBint){

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

    //5.Hacemos que la variable P creada al inicio del método sea igual a la mantisa de b
    P = mantisaBint;

    //6.Asignamos el bit de guarda, de recondeo y el sticky
    //Paso P a qstring para poder acceder a los valores de posiciones concretas
    QString Pstring = QString::number(P);

 //------------------IMPORTANTE: PASAR d A DECIMAL PARA PODER ACCEDER A LAS POSICIONES (d-1), (d-2),... !!! SI NO LO HACEMOS LO DE ABAJO DE ESTE PASO NO VA A FUNCIONAR-------------------------
 //No lo hago yo ahora pq creo que Magda tenia una funcion que le paso guille que ya lo hace  y para no perder tiempo
    int dInt = d.toInt();

    if(dInt == 1){ //Si d=1 solo existe g, no existe ni r ni st

        g = Pstring[Pstring.length()-1-dInt-1].digitValue();
    }
    if(dInt == 2 or dInt == 3){ //Si d=2 existen g y r, pero no existe st

/*------------  DUDA: El en clase dijo que cuando d <=3 existen las 3 cosas, pero si d=3, el sitcky queda OR de solo un valor
                entonces yo creo que si d=3 se queda el valor de sticky inicializado al principio, SOLUCIONAR ESTA DUDA */

        //Se empieza a contar P0 desde el final del QString por lo que es (length-1) -d - numero que queramos restar en cada caso
        g = Pstring[Pstring.length()-1-dInt-1].digitValue();
        r = Pstring[Pstring.length()-1-dInt-2].digitValue();
    }
    if(dInt>3){ //Si d>=3 existen las 3 cosas

        //Guarda = Pd-1
        g = Pstring[Pstring.length()-1-dInt-1].digitValue(); //digitValue es para pasar de QChar a int
        //Redondeo = Pd-2
        r = Pstring[Pstring.length()-1-dInt-2].digitValue();
        //Sticky = OR(Pd-3,Pd-4,...,P0)
        int comienzoOR = Pstring[Pstring.length()-1-dInt-3].digitValue();
        int OR;
        for (int i=Pstring.length()-1-dInt-3; i< Pstring.length(); i++){

            OR = comienzoOR | Pstring[i].digitValue();
            comienzoOR = OR;
        }
        st = OR;
    }
    //Si d=0 se mantienen los valores inicializados de g, r y st

    //7.Si los signos son distintos, desplazamos P a la derecha d bits introduciendo 1 x la izquierda
    if(signoAint!=signoBint){

        //Paso P a QString para poder desplazar
        QString newP;
        for(int i=0; i<dInt; i++){ //Agregamos tantos 1s a la izq como d

            newP = newP + "1";
        }
        for(int j=0; j<Pstring.length()-1-dInt; j++){ //Rellenamos con las posiciones de P de 0 a lenght-d

            newP = newP + Pstring[j];
        }

        Pstring = newP; //Aquí ya tenemos el nuevo P
        P = Pstring.toInt();
    }
    else{ //Sino, lo mismo pero introduciendo 0s

        QString newP;
        for(int i=0; i<dInt; i++){ //Agregamos tantos 0s a la izq como d

            newP = newP + "0";
        }
        for(int j=0; j<Pstring.length()-1-dInt; j++){ //Rellenamos con las posiciones de P de 0 a lenght-d

            newP = newP + Pstring[j];
        }

        Pstring = newP; //Aquí ya tenemos el nuevo P
        P = Pstring.toInt();
    }

    //8.Hacemos: P = mantisaA + P; y c1= acarreo de la suma entera
    QString sumaMantisayP = sumaBinario(mantisaAint, P);
    int c1;

    if(sumaMantisayP.length() == 24){ //Esto significa que no ha habido acarreo en el utimo digito sumado

        P = sumaMantisayP.toInt();
        Pstring = sumaMantisayP;

        c1 = 0;
    }
    else{ //Si tiene más de 24 de longitud será que tiene 25 de longitud y es que ha habido acarreo en el ultimo digito sumado

        sumaMantisayP.remove(0, 1);
        P = sumaMantisayP.toInt();
        Pstring = sumaMantisayP;

        c1 = 1;

    }

    //9.Si los signos son distintos Y (Pn-1 = 1) Y c1 = 0: complemento a 2 de p y cambiamos variable complementada_p (Solo se entra si d=0)
    if((signoAint!=signoBint) && (Pstring[0].digitValue()==1) && (c1==0)){

        QString Pcomplemento = sumaBinario(P , 000000000000000000000001);    //Sumamos 1 a exponente de b
        for(int i=0; i<Pcomplemento.length(); i++){ //cambiamos los 0s por 1s y los 1s por 0s

            if(Pcomplemento[i]=='0'){
                Pcomplemento[i]=='1';
            }
            else{
                Pcomplemento[i]=='0';
            }
        } //Aqui acaba el calculo del complemento a 2 de eb

        P = Pcomplemento.toInt();
    }

    //10.

}
