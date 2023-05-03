#ifndef ALU_H
#define ALU_H
#include <QString>

class alu
{
public:
    alu();
    ~alu(void);

    QString suma(QString signoA, QString exponenteA, QString mantisaA, QString signoB, QString exponenteB, QString mantisaB);

    QString sumaBinario(int a, int b);

    int binarioADecimal(int binario);

    QString complemento2(int num);

    QString multiplicacion();

    QString division();

    QString getPrueba();

private:

    int signoResultado;
    int mantisaResultado;
    int exponenteResultado;
    QString prueba;
};

#endif // ALU_H
