#ifndef ALU_H
#define ALU_H
#include <QString>

class alu
{
public:
    alu();

    QString suma(QString signoA, QString exponenteA, QString mantisaA, QString signoB, QString exponenteB, QString mantisaB);

    QString sumaBinario(int a, int b);

    QString complemento2(int num);

    QString multiplicacion();

    QString division();

private:

    int signoResultado;
    int mantisaResultado;
    int exponenteResultado;
};

#endif // ALU_H
