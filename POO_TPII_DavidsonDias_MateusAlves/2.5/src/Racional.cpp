#include "Racional.h"
#include<iostream>

using namespace std;

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

void Racional::print() const
{
    cout<<numerador<<"/";
    cout<<denominador<<endl;
}

void Racional::add(const int n,int d)
{
    if(d==0)///Tratamento de indeterminação.
        d=1;

    simplificar(n,d);
}

Racional::Racional(int n,int d)
{
    if(d==0)///Tratamento de indeterminação.
        d=1;

    simplificar(n,d);
}

Racional::~Racional()
{
    //dtor
}

void Racional::subtrair(const Racional a ,const Racional b)
{
    int x,y;

    x=(b.denominador*a.numerador)-(a.denominador*b.numerador);
    y=(a.denominador*b.denominador);

    simplificar(x,y);
}

void Racional::multiplicar(const Racional a,const Racional b)
{
    int x,y;
    x=(a.numerador*b.numerador);
    y=(a.denominador*b.denominador);

    simplificar(x,y);

}
void Racional::dividir(const Racional a,const Racional b)
{
    int x,y;
    x=(a.numerador*b.denominador);
    y=(a.denominador*b.numerador);

    simplificar(x,y);

}

void Racional::printflutuante() const
{
    float x;

    x=(float)numerador/denominador;///Numerador convertido para float para efetuar a divisão

    cout<<x<<endl;
}


