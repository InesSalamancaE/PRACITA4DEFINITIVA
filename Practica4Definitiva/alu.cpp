#include "alu.h"
#include<bitset>
#include <string>
#include "mainwindow.h"

using std::bitset;
#include <iostream>
using namespace std;

alu::alu()
{

}

alu::~alu(void){

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

int alu::binarioADecimal(int binario){

    int dec = 0;
    int i = 0;
    int rem;

    while(binario!=0){

        rem = binario%10;
        binario/=10;
        dec += rem*pow(2,i);
        ++i;

    }

    return dec;

}

/* Metodo para ir pudiendo comprobar cosas:
    1. Tener la variable que se quiere probar.
    2. Meterla en this->prueba como QString
    3. En mainwindow he llamado a este metodo para que salga en un lineText lo que queremos probar
*/
QString alu::getPrueba(){

    return this->prueba;
}

QString alu::suma(QString signoA, QString exponenteA, QString mantisaA, QString signoB, QString exponenteB, QString mantisaB){
    //COMPROBACIOIN DE DATOS DE ENTRADA HECHA: OK

    //Pasamos a int los parámetros del método
    int signoAint = signoA.toInt();
    int exponenteAint = exponenteA.toInt();
    //double mantisaAdouble = mantisaA.toDouble();
    //int mantisaAint = static_cast<int>(mantisaAdouble);
    quint64 mantisaAint = static_cast<quint64>(mantisaA.toULongLong());     //PROBLEMA: Al pasar mantisaA a int nos devuelve 0
    int signoBint = signoB.toInt();
    int exponenteBint = exponenteB.toInt();
    quint64 mantisaBint = mantisaB.toInt();     //PROBLEMA: Al pasar mantisaB a int nos devuelve 0


    //COMPROBACION INTS: Mantisas no se pasan bien a int. Solucionarlo o trabajar siempre con los QStrings.

    //1.Inicialización de variables
    int P = 0;
    int g = 0;
    int r = 0;
    int st = 0;
    int n = 24;
    bool Operandos_intercambiados = false;
    bool Complemento_P = false;

    //COMPROBACION PASO 1: OK

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

    //COPROBACION PASO 2: OK para numeros positivos (Con negativos peta y se cierra, no se si es de este paso o de los siguientes)

    //3.
    int exponenteSumaInt = exponenteAint;
    QString exponenteSuma = exponenteA;
    int exponenteDecimal = binarioADecimal(exponenteSumaInt); //CALCULADO EN DECIMAL, PQ EN LAS DIAPOS LO USA EN DECIMAL

    int exponenteADecimal = binarioADecimal(exponenteAint);
    int exponenteBDecimal = binarioADecimal(exponenteBint);
    int d = exponenteADecimal - exponenteBDecimal;

    this->prueba = QString::number(exponenteADecimal) + " " + QString::number(exponenteBDecimal) + " "  + QString::number(d) + " " ;
    QString dString = QString::number(d);

    //COMPROBACION PASO 3: OK para numeros positivos

    //4.Si los signos son distintos, la mantisa de b pasa a ser el complemento OK
    if(signoAint!=signoBint){

        QString mbComplemento = sumaBinario(mantisaBint, 000000000000000000000001);    //Sumamos 1 a exponente de b
        for(int i=0; i<mbComplemento.length(); i++){ //cambiamos los 0s por 1s y los 1s por 0s

            if(mbComplemento[i]=='0'){
                mbComplemento[i]='1';
            }
            else{
                mbComplemento[i]='0';
            }
        } //Aqui acaba el calculo del complemento a 2 de eb

        mantisaB = mbComplemento;
        mantisaBint = mantisaB.toInt();

    }

    //5.Hacemos que la variable P creada al inicio del método sea igual a la mantisa de b OK
    P = mantisaBint;

    //6.Asignamos el bit de guarda, de recondeo y el sticky ALGO NO VA BIEN
    //Paso P a qstring para poder acceder a los valores de posiciones concretas
    QString Pstring = QString::number(P);

    //------------------IMPORTANTE: PASAR d A DECIMAL PARA PODER ACCEDER A LAS POSICIONES (d-1), (d-2),... !!! SI NO LO HACEMOS LO DE ABAJO DE ESTE PASO NO VA A FUNCIONAR-------------------------
    //No lo hago yo ahora pq creo que Magda tenia una funcion que le paso guille que ya lo hace  y para no perder tiempo

    if(d == 1){ //Si d=1 solo existe g, no existe ni r ni st

        g = Pstring[Pstring.length()-1-d-1].digitValue();
    }
    if(d == 2 or d == 3){ //Si d=2 existen g y r, pero no existe st

        /*------------  DUDA: El en clase dijo que cuando d <=3 existen las 3 cosas, pero si d=3, el sitcky queda OR de solo un valor
                entonces yo creo que si d=3 se queda el valor de sticky inicializado al principio, SOLUCIONAR ESTA DUDA */

        //Se empieza a contar P0 desde el final del QString por lo que es (length-1) -d - numero que queramos restar en cada caso
        g = Pstring[Pstring.length()-1-d-1].digitValue();
        r = Pstring[Pstring.length()-1-d-2].digitValue();
    }
    if(d>3){ //Si d>=3 existen las 3 cosas

        //Guarda = Pd-1
        g = Pstring[Pstring.length()-1-d-1].digitValue(); //digitValue es para pasar de QChar a int
        //Redondeo = Pd-2
        r = Pstring[Pstring.length()-1-d-2].digitValue();
        //Sticky = OR(Pd-3,Pd-4,...,P0)
        int comienzoOR = Pstring[Pstring.length()-1-d-3].digitValue();
        int OR;
        for (int i=Pstring.length()-1-d-3; i< Pstring.length(); i++){

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
        for(int i=0; i<d; i++){ //Agregamos tantos 1s a la izq como d

            newP = newP + "1";
        }
        for(int j=0; j<Pstring.length()-1-d; j++){ //Rellenamos con las posiciones de P de 0 a lenght-d

            newP = newP + Pstring[j];
        }

        Pstring = newP; //Aquí ya tenemos el nuevo P
        P = Pstring.toInt();
    }
    else{ //Sino, lo mismo pero introduciendo 0s

        QString newP;
        for(int i=0; i<d; i++){ //Agregamos tantos 0s a la izq como d

            newP = newP + "0";
        }
        for(int j=0; j<Pstring.length()-1-d; j++){ //Rellenamos con las posiciones de P de 0 a lenght-d

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
                Pcomplemento[i]='1';
            }
            else{
                Pcomplemento[i]='0';
            }
        } //Aqui acaba el calculo del complemento a 2 de eb

        P = Pcomplemento.toInt();
    }

    //10.Si los signos son iguales y c1=0:
    QString Pstr = QString::number(P);
    if ((signoAint==signoBint) && (c1==0)){
        //St = OR()g, r, st), que inicialmente será 0, y r = P0
        st = g || r || st;
        r = Pstr.at(0).digitValue();
        //Desplazar un bit a la derecha, introducimos el bit C1 por la izquierda

        string cadena;
        cadena = Pstr.toStdString();
        string ultimo = cadena.erase(cadena.size() -1, 1);
        Pstr = QString::fromUtf8(ultimo.c_str());

        if (c1){
            Pstr = '1' + Pstr;

        } else{
            Pstr = '0' + Pstr;
        }

        //Ajustamos el exponente de la suma
        //OJO, hay que repasar esto, porque no se si se suma 1 porque el ejemplo es así, o porque es 1 :( NOTA ALI: SI QUE ES ASI CREO (siempre 1)
        exponenteSumaInt = exponenteSumaInt + 1;
        exponenteSuma = (char)exponenteSumaInt;


    } else {
        //Calcular Kbits que es necesario desplazar P para que sea una mantisa normalizada
        //Para normalizar la mantisa, el primero tiene que ser un 1, por tanto, hacemos un bucle hasta encontrar un 1
        int K = 0;
        for (int i=0; i<Pstr.length(); i++){
            if (Pstr[i] == '1'){
                K = i;
                break; //NOTA ALI: No se si es muy bueno meter un break dentro de aquí, mejor evitarlo
            }
        }


        if (K == 0){
            st = r || st;
            r = g;

        }
        if(K>1){ //NOTA ALI: Lo he cambiado a k>1 en vez de else, pq cuando k=1 no tiene que entrar aquí
            r = 0;
            st = 0;
        }

        //Desplazar (P, g) a la izquierda K bits FALTA HACERLO //NOTA ALI: hecho pero revisar -> he metido por la derecha g
        QString newP2 = QString::number(P); //Paso P a QString para poder trabajar con el mejor
        newP2.remove(0, K); //Borramos las primeras K posiciones de P
        for(int i=0; i<K; i++){ //Añadimas K veces por la derecha g

            newP2 = newP2 + QString::number(g);
        }

        Pstring = newP2; //Actualizo valor de P en formato QString
        P = newP2.toInt(); //Actualizao valor de P en formato int

        //ajustar el exponente de la suma
        exponenteSumaInt = exponenteSumaInt - K;
        exponenteSuma = (char)exponenteSumaInt;



    }

    //11. Redondear P
    int c2;

    if ((r==1 && st ==1) || (r == 1 && st == 0 && P == 1)){
        //P = P+1
        QString sumaP = sumaBinario(P, 00000000000000000000001); //NOTA ALI: he cambiado el 1 por 1 pero con 23 bits como tiene P porque sino creo que nuestro metodo no funciona
        // C = acarreo
        if(sumaP.length() == 24){ //Esto significa que no ha habido acarreo en el utimo digito sumado

            P = sumaP.toInt();
            Pstring = sumaP;

            c2 = 0;
        }
        else{ //Si tiene más de 24 de longitud será que tiene 25 de longitud y es que ha habido acarreo en el ultimo digito sumado

            sumaP.remove(0, 1);
            P = sumaP.toInt();
            Pstring = sumaP;

            c2 = 1;

        }

        if (c2 == 1){
            //Desplazar un bit a la derecha (C2, P) y ajustar el exponente de la suma FALTA ESTA PARTE
            QString newP3 = QString::number(P); //Paso P a QString para poder trabajar mejor con el
            newP3.remove(newP3.length()-1, 1); //Quito el ultimo digito de P
            newP3 = QString::number(c2) + newP3; //Le añado por delanter c2

            Pstring = newP3; //Actualizo valor de P en formato QString
            P = newP3.toInt(); //Actualizao valor de P en formato int

            exponenteSumaInt = exponenteSumaInt + 1;
            exponenteSuma = QString::number(exponenteSumaInt);

            this->exponenteResultado = exponenteSumaInt; //NOTA ALI: ya asignamos al atributo de clase que representa el exponente del resultado el valor calculado
        }


    }

    int mantisaSuma = P;
    //NOTA ALI: Aqui lo guardo ya en el atributo de clase que representa la mantisa del resultaddo:
    this->mantisaResultado = P;


    //12. Calcular el signo del resultado

    int signoSuma;

    if (Operandos_intercambiados == false && Complemento_P == true){
        signoSuma = signoBint;
        this->signoResultado = signoBint;
    } else{
        signoSuma = signoAint;
        this->signoResultado = signoAint;
    }

    /*En este punto ya deberían estar guardados los valores de signo, exponente y mantisa en sus correspondientes atributos de clase,
     para poder simplemente al clickar sobre el igual de la interfaz de usuario pasarlo a decimal y hexadecimal y mostrarlo */

    return QString::number(this->signoResultado) + QString::number(this->mantisaResultado) + QString::number(this->exponenteResultado);
}

QString alu::multiplicacion(){
    QString answer;
    return answer;

}
QString alu::division(){
    QString answer;
    return answer;
}
