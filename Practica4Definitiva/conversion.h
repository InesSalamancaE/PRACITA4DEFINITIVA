#ifndef CONVERSION_H
#define CONVERSION_H


class conversion
{
public:
    conversion();
    void floattoIEE (float numAconvertir);
    void floattoIEE2 ();
    void IEEtofloat ();
    void IEEtofloat2 ();

private:

    float numReal;
    float numIEEE;
    float signo;
    float exponente;
    float fraccionaria;

};


#endif // CONVERSION_H
