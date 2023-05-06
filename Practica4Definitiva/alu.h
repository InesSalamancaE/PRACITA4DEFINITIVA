#ifndef ALU_H
#define ALU_H
#include <QString>

class alu
{
public:
    alu();
    ~alu(void);

    QString suma(QString signoA, QString exponenteA, QString mantisaA, QString signoB, QString exponenteB, QString mantisaB);

    QString multiplicacion(QString signoAString, QString exponenteAString, QString mantisaA, QString signoBString, QString exponenteBString, QString mantisaB);

    QString division();

    QString complemento2(QString num);

    QString sumaBinario(QString a, QString b);

    int binarioADecimal(int binario);

    QString decimalABinario(int numero, int longitud);

    QString multiplicacionBinaria(QString mantisaA, QString mantisaB);

private:

    QString signoResultado;
    QString mantisaResultado;
    QString exponenteResultado;
};

#endif // ALU_H
