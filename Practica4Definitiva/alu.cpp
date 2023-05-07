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


QString alu::suma(QString signoAString, QString exponenteAString, QString mantisaA, QString signoBString, QString exponenteBString, QString mantisaB){

    //Pasamos a int los parámetros del método
    int signoA = signoAString.toInt();
    int exponenteA = binarioADecimal(exponenteAString.toInt());
    int signoB = signoBString.toInt();
    int exponenteB = binarioADecimal(exponenteBString.toInt());

    //EXCEPCION: restar el mismo numero a si mismo (que da 0)
    if((signoA!=signoB) && (exponenteA==exponenteB) && (mantisaA==mantisaB)){

        this->signoResultado = "0";
        this->exponenteResultado = "00000000";
        this->mantisaResultado = "00000000000000000000000";

        return (this->signoResultado + " " +  this->exponenteResultado + " " + this->mantisaResultado);
    }

    //EXCEPCION: Si el exponenete es mayor de 254, infinito.
    if(exponenteA>254 || exponenteB>254){
        this->signoResultado = "0";
        this->exponenteResultado = "11111111";
        this->mantisaResultado = "00000000000000000000000";

        return (this->signoResultado + " " +  this->exponenteResultado + " " + this->mantisaResultado);
    }

    //1.Inicialización de variables
    QString p = 0; //Alba: Qstring porque estamos trabajando con mantisas en QString
    int g = 0;
    int r = 0;
    int st = 0;
    int n = 24;
    bool operandos_intercambiados = false;
    bool complemento_P = false;


    //2.Siempre hay que sumar NumGrando + NumPequeño.
    if(exponenteA<exponenteB){
        //Alba: He quitado los qstring de signo y exponente pq sobran, y el int de mantisa
        int signoAuxiliar = signoA;
        int exponenteAuxiliar = exponenteA;
        QString mantisaAuxiliarString = mantisaA;

        signoA = signoB;
        exponenteA = exponenteB;
        signoB = signoAuxiliar;
        exponenteB = exponenteAuxiliar;

        mantisaA = mantisaB;
        mantisaB = mantisaAuxiliarString;

        operandos_intercambiados = true;
    }

    //3.
    int exponenteSuma = exponenteA;
    int d = exponenteA - exponenteB;

    //4.Si los signos son distintos, la mantisa de b pasa a ser el complemento OK
    if(signoA!=signoB){

        mantisaB = complemento2(mantisaB);
        //complemento_P=true;
    }

    //5.Hacemos que la variable P creada al inicio del método sea igual a la mantisa de b OK
    p = mantisaB;

    //6.Asignamos el bit de guarda, de recondeo y el sticky ALGO NO VA BIEN

    if(d == 1){ //Si d=1 solo existe g, no existe ni r ni st

        g = p[p.length()-1-d-1].digitValue();
    }
    if(d == 2){ //Si d=2 existen g y r, pero no existe st

        /*------------  DUDA: El en clase dijo que cuando d <=3 existen las 3 cosas, pero si d=3, el sitcky queda OR de solo un valor
                entonces yo creo que si d=3 se queda el valor de sticky inicializado al principio, SOLUCIONAR ESTA DUDA
                --Si d=3, comprueba solo con un bit, si es 1, st=1*/

        //Se empieza a contar P0 desde el final del QString por lo que es (length-1) -d - numero que queramos restar en cada caso
        g = p[p.length()-1-d-1].digitValue();
        r = p[p.length()-1-d-2].digitValue();
    }
    if(d>=3 && d<p.length()){ //Si d>=3 existen las 3 cosas

        //Guarda = Pd-1
        g = p[p.length()-1-d-1].digitValue(); //digitValue es para pasar de QChar a int
        //Redondeo = Pd-2
        r = p[p.length()-1-d-2].digitValue();
        //Sticky = OR(Pd-3,Pd-4,...,P0)
        int comienzoOR = p[p.length()-1-d-3].digitValue();
        int OR;
        for (int i=(p.length()-1-d-4); i<p.length(); i++){

            OR = comienzoOR || p[i].digitValue();
            comienzoOR = OR;
        }
        st = comienzoOR;
    }
    //Si d=0 se mantienen los valores inicializados de g, r y st

    //7.Si los signos son distintos, desplazamos P a la derecha d bits introduciendo 1 x la izquierda
    if(signoA!=signoB){ //Si el signo es distinto, se hace prepend con 1

        for(int i=0; i<d;i++){
            p.remove(p.length()-1, 1);
            p.prepend("1");
        }
    }else{ //Si el signo es igual, se hace prepend con 0
        for(int i=0; i<d;i++){
            p.remove(p.length()-1, 1);
            p.prepend("0");
        }
    }

    //8.Hacemos: P = mantisaA + P; y c1= acarreo de la suma entera
    QString sumaMantisayP = sumaBinario(mantisaA, p);
    int c1;

    if(sumaMantisayP.length() == 24){ //Esto significa que no ha habido acarreo en el utimo digito sumado
        p = sumaMantisayP;
        c1 = 0;
    }else{ //Si tiene más de 24 de longitud será que tiene 25 de longitud y es que ha habido acarreo en el ultimo digito sumado

        sumaMantisayP.remove(0, 1);
        p = sumaMantisayP;
        c1 = 1;
    }

    //9.Si los signos son distintos Y (Pn-1 = 1) Y c1 = 0: complemento a 2 de p y cambiamos variable complementada_p (Solo se entra si d=0)
    if((signoA!=signoB) && (p[0].digitValue()==1) && (c1==0)){ //Pn-1 es P23, son 24bits y 0 es el de la dcha
        p = complemento2(p);
        complemento_P=true;
    }
//Hasta aqui, paso 8 funciona fijo, paso 9 nos fiamos porque no es gran cosha
    //10.Si los signos son iguales y c1=0:
    if ((signoA==signoB) && (c1==1)){
        //St = OR()g, r, st), que inicialmente será 0, y r = P0
        st = g || r || st;
        r = p[p.length()-1].digitValue();

        //Desplazar un bit a la derecha, introducimos el bit C1 por la izquierda
        p.remove(p.length()-1,1);
        p.prepend(QString::number(c1));

        //Ajustamos el exponente de la suma
        exponenteSuma = exponenteSuma+1;
        this->exponenteResultado = decimalABinario(exponenteSuma, 8);

    } else {
        //Calcular Kbits que es necesario desplazar P para que sea una mantisa normalizada
        //Para normalizar la mantisa, el primero tiene que ser un 1, por tanto, hacemos un bucle hasta encontrar un 1
        int k = 0;
        for (int i=0; i<p.length(); i++){
            if (p[i] == '1'){
                k = i;
                break; //NOTA ALI: No se si es muy bueno meter un break dentro de aquí, mejor evitarlo
            }
        }

        if (k == 0){
            st = r || st;
            r = g;

        }
        if(k>1){ //NOTA ALI: Lo he cambiado a k>1 en vez de else, pq cuando k=1 no tiene que entrar aquí
            r = 0;
            st = 0;
        }

        //Desplazar (p, g) a la izquierda k bits FALTA HACERLO //NOTA ALI: hecho pero revisar -> he metido por la derecha g
        p.remove(0, k);
        for(int i=0; i<k; i++){ //Añadimas K veces por la derecha g
            p.append(QString::number(g));
        }

        //Ajustar el exponente de la suma
        exponenteSuma = exponenteSuma - k;
        this->exponenteResultado = decimalABinario(exponenteSuma, 8);

    }

    //11. Redondear P
    int c2;

    if ((r==1 && st ==1) || (r == 1 && st == 0 && p[p.length()-1] == '1')){
        //P = P+1
        QString sumaP = sumaBinario(p, "00000000000000000000001"); //NOTA ALI: he cambiado el 1 por 1 pero con 23 bits como tiene P porque sino creo que nuestro metodo no funciona
        // C = acarreo
        if(sumaP.length() == 24){ //Esto significa que no ha habido acarreo en el utimo digito sumado
            p=sumaP;
            c2 = 0;
        }
        else{ //Si tiene más de 24 de longitud será que tiene 25 de longitud y es que ha habido acarreo en el ultimo digito sumado

            sumaP.remove(0, 1);
            p=sumaP;
            c2 = 1;

        }

        if (c2 == 1){
            //Desplazar un bit a la derecha (C2, P) y ajustar el exponente de la suma FALTA ESTA PARTE
            p.remove(p.length()-1,1);
            p.prepend(QString::number(c2));

            exponenteSuma = exponenteSuma + 1;

        }


    }

    //NOTA ALI: Aqui lo guardo ya en el atributo de clase que representa la mantisa del resultaddo:
    //Ya esta la mantisa calculada pero se normaliza quitandole el primer 1
    this->mantisaResultado = p.remove(0,1);
//HASTA AQUI REVISADO, 11 SIN DEBUG AUN

    //12. Calcular el signo del resultado

    if (operandos_intercambiados == false && complemento_P == true){
        this->signoResultado = QString::number(signoB);
    } else{
        this->signoResultado = QString::number(signoA);
    }

    //En este punto ya deberían estar guardados los valores de signo, exponente y mantisa en sus correspondientes atributos de clase,
     //para poder simplemente al clickar sobre el igual de la interfaz de usuario pasarlo a decimal y hexadecimal y mostrarlo

    return (this->signoResultado + " " +  this->exponenteResultado + " " + this->mantisaResultado);

}

QString alu::multiplicacion(QString signoAString, QString exponenteAString, QString mantisaA, QString signoBString, QString exponenteBString, QString mantisaB){
    QString answer;
    //Hay que pasar los signos y los exponentes de QString a int
    int signoA = signoAString.toInt();
    int signoB = signoBString.toInt();
    int exponenteA = binarioADecimal(exponenteAString.toInt()); //No se si los exponenetes se trabajan en decimal o en binario
    int exponenteB = binarioADecimal(exponenteBString.toInt());


    //1. Signo del producto es SignoA * SignoB
    int signoProducto = signoA ^ signoB;

    //2. Exponente del producto es exponenteA + exponenteB
    int exponenteProducto = (exponenteA-127) + (exponenteB-127) +127; //Restamos a cada uno 127 y luego lo sumamos a la suma para que no desborde

    //3. Calculo de la mantisa del producto, mantisaProducto (MULTIPLICACION BINARIA SIN SIGNO)
    //i
    QString multiplicacionBinariaMantisas = multiplicacionBinaria(mantisaA, mantisaB);
    QString p = multiplicacionBinariaMantisas.split(" ")[0];
    QString a = multiplicacionBinariaMantisas.split(" ")[1];

    //ii
    if(p[0]=='0'){

        p.remove(0,1);
        p.append(a[0]);
        a.remove(0,1);
        a.append("0");
    }else{

        exponenteProducto++;
    }

    //iii
    int r = a[0].digitValue();

    //iv
    int st;
    int or1 = a[1].digitValue();

    for(int i=2; i<a.length(); i++){

        int OR = or1 || a[i].digitValue();
        or1 = OR;
    }

    st = or1;

    //v
    if((r==1 && st==1) || (r==1 && st==0 && p[p.length()-1]=='0')){

        p = sumaBinario(p, "000000000000000000000001");
    }

    //COMPROBACION DESBORDAMIENTOS
    //1.Hay desbordamiento si el exponente del producto es mas mayor a 254
    if (exponenteProducto>254){
        //Hay desbordamiento infinito OJO, QUE NO SE QUE TIENE QUE DEVOLVER SI HAY DESBORDAMIENTO
        return "overflow";
    }
    //2. underflow
    int res;
    if (exponenteProducto<1){ //Entendemos que el exponente mínimo es 1
        res= 1 - exponenteProducto;
        if (res>=24){ //Entendemos que el número de bits en la mantisa es 24
            //Underflow
            return "Underflow";
        } else{
            //Entramos en el apartado denormal, por tanto desplazamos aritméticamente (P,A), t bits a la derecha
            for (int i=0; i<res; i++){
                p.insert(p.begin(), 0);
                p.pop_back();
            }


            //El exponente del producto es el exponente mínimo, es decir 1
            exponenteProducto = 1;
        }
    }


    //TRATAMIENTO ESPECIFICO CUANDO HAY OPERANDOS DENORMALES
    int res1 = exponenteProducto - 1;
    int res2 = ;
    i = 0;
    //Como el caso 1 es igual tratamiento de datos, no lo tenemos en cuenta

    //Caso 2
    if(exponenteProducto>1){
        res = exponenteProducto -1;
        while(res2==-1 && i<48){
            if (p.at(i) == 1){
                res2=i;
            }
            i++;
        }

        if(res1 < res2){
            res = res1;
        } else{
            res = res2;
        }
        exponenteProducto= res;
        //Desplazar aritmeticamente (P,A) t bits a la izquierda
        for (int e = 0; e < res; ++e) {
            p.push_back(0);
            p.erase(p.begin());
        }
    }

    //Caso 3, el resultado es directamente denormal
    if (exponenteProducto == 1){
        return "Denormal";
    }

    //mp = p DUDO QUE ESTO ESTË BIEN
    mantisaResultado = p;




    return answer;

}
QString alu::division(){
    QString answer;
    return answer;
}

QString alu::complemento2(QString mantisa){
    //Alba:La suma 1 va despues de hacer el cambio de 1 por 0 y viceversa, he quitado el mantisaInt
    QString mbComplemento;
    for(int i=0; i<mantisa.length(); i++){ //cambiamos los 0s por 1s y los 1s por 0s

        if(mantisa.at(i)=='0'){
            mbComplemento.append("1");
        }
        else{
            mbComplemento.append("0");
        }
    } //Aqui acaba el calculo del complemento a 2 de eb
    mbComplemento = sumaBinario(mbComplemento, "000000000000000000000001");  //Sumamos 1 a exponente de b
    return mbComplemento;
}

//Método para sumar dos numeros binarios (Pasamos siempre dos nums con el mismo numero de bist)
//Alba: he cambiado que al metodo le lleguen dos QString, no he revisado si lo hace bn
QString alu::sumaBinario(QString a, QString b){
    QString solucion;
    int acarreo = 0;
    int i = a.size() - 1;
    int j = b.size() - 1;

    while (i >= 0 || j >= 0) {
        int suma = acarreo;

        if (i >= 0) {
            suma += a[i].digitValue();
            i--;
        }
        if (j >= 0) {
            suma += b[j].digitValue();
            j--;
        }

        solucion.prepend(QString::number(suma % 2));
        acarreo = suma / 2;
    }

    if (acarreo > 0) {
        solucion.prepend(QString::number(acarreo));
    }

    return solucion;
}

//Método de binario a decimal
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

//Metodo decimal a binario
QString alu::decimalABinario(int numero,int longitud){
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

QString alu::multiplicacionBinaria(QString mantisaA, QString mantisaB){

    //1.Almacenar A, B y P
    QString a = mantisaA;
    QString b = mantisaB;
    QString p = "000000000000000000000000";
    int c;

    for(int i=0; i<mantisaA.length(); i++){
        //i
        if(a[a.length()-1] == '1'){

            QString suma = sumaBinario(p, b);
            // C = acarreo
            if(suma.length() == 24){ //Esto significa que no ha habido acarreo en el utimo digito sumado
                p=suma;
                c = 0;
            }
            else{ //Si tiene más de 24 de longitud será que tiene 25 de longitud y es que ha habido acarreo en el ultimo digito sumado

                suma.remove(0, 1);
                p=suma;
                c = 1;

            }
        } //El else seria hacer p = p + 0
        //ii
        a.remove(a.length()-1,1);
        a.prepend(p[p.length()-1]);
        p.remove(p.length()-1,1);
        p.prepend(QString::number(c));
    }

    //3.Producto: (P,A)
    return p + " " + a;

}
