#include "Racional.h"
#include<iostream>

using namespace std;

namespace Matematica{
void Racional::simplificar(int a,int b)
{
    ///Utilizamos o MDC para fazer a simplificação dos valores
    int resto,aux1=a,aux2=b;

    while(b != 0)
    {
        resto = a % b;
        a = b;
        b = resto;
    }

    numerador=aux1/a;
    denominador=aux2/a;
}

void Racional::add(const int n,int d)
{
    if(d==0)///Tratamento de indeterminação.
        d=1;

    simplificar(n,d);
}

Racional::Racional(const int n,int d)
{
    if(d==0)///Tratamento de indeterminação.
        d=1;

    simplificar(n,d);
}

Racional::Racional(const double d)
{
    simplificar(d*10E5,10E5);
}

Racional::~Racional()
{
    //dtor
}

Racional Racional::operator + (const Racional& h) const
{
    int x,y;

    x=(h.denominador*numerador)+(denominador*h.numerador);
    y=(denominador*h.denominador);

    Racional aux(x,y);

    return aux;
}

Racional Racional::operator - (const Racional& h) const
{
    int x,y;

    x=(h.denominador*numerador)-(denominador*h.numerador);
    y=(denominador*h.denominador);

    Racional aux(x,y);

    return aux;
}

Racional Racional::operator * (const Racional& h)const
{
    int x,y;
    x=(numerador*h.numerador);
    y=(denominador*h.denominador);

     Racional aux(x,y);

     return aux;

}
Racional Racional::operator / (const Racional& h)const
{
    int x,y;
    x=(numerador*h.denominador);
    y=(denominador*h.numerador);

    Racional aux(x,y);

    return aux;
}

void Racional::printflutuante() const
{
    float x;

    x=(float)numerador/denominador;///Numerador convertido para float para efetuar a divisão

    cout<<x<<endl;
}

ostream& operator << (ostream& op, const Racional& h)
{
    op<<h.numerador<<"/";
    op<<h.denominador<<endl;
    return op;
}
}


