#ifndef ALU_H
#define ALU_H
#include <QString>

class alu
{
public:
    alu();
    ~alu(void);

    QString suma(QString signoA, QString exponenteA, QString mantisaA, QString signoB, QString exponenteB, QString mantisaB);

    QString sumaBinario(QString a, QString b);

    int binarioADecimal(int binario);

    QString complemento2(QString num);

    QString multiplicacion(QString signoAString, QString exponenteAString, QString mantisaA, QString signoBString, QString exponenteBString, QString mantisaB);

    QString division();

     QString getPrueba();


private:

    int signoResultado;
    int mantisaResultado;
    int exponenteResultado;
     QString prueba;
};

#endif // ALU_H
