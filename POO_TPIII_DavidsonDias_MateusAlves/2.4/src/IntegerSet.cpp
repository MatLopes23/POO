#include "IntegerSet.h"
#include<array>
#include<iostream>
#include<fstream>
#include<string>


namespace Matematica
{
IntegerSet::IntegerSet()
{
    a.fill(false); /// Preenche as posições do array como 'false'
}

IntegerSet::~IntegerSet()
{
    //dtor
}

IntegerSet& IntegerSet::operator += (const int k)
{
    if(k>=0&&k<=100)///Restrição para o valor
    {
        a[k]= {true};
        return *this;
    }

}

IntegerSet& IntegerSet::operator -= (const int k)
{
    if(k>=0&&k<=100) ///Restrição para o valor
    {
        a[k]= {false};
        return *this;
    }

}

IntegerSet IntegerSet::operator + (const IntegerSet& h)const
{
    IntegerSet aux;
    for(int i=0; i<101; i++)
        aux.a[i]=a[i]+h.a[i];

    return aux;

}

IntegerSet IntegerSet::operator & (const IntegerSet& h)const
{
    IntegerSet aux;
    for(int i=0; i<101; i++)
        aux.a[i]=a[i]*h.a[i];

    return aux;
}

std::ostream& operator << (std::ostream& op, const IntegerSet& h)
{
    int aux=0;

    for (int i = 0; i < 101; i++)
    {
        if(h.a[i]==true)
        {
            op << i <<" ";
            aux++;
        }
    }
    if(aux==0)
        op <<"---";
    op<<std::endl;

    return op;
}

std::istream& operator >> (std::istream& op, IntegerSet& h)
{
    int aux;

    op>>aux;
    h+=aux;

    return op;
}


IntegerSet& IntegerSet::operator >> (const std::string& nomeArquivo)
{
    std::ifstream arq(nomeArquivo.c_str());
    int x;
    while(arq>>x)
        *this+=x;
}

bool IntegerSet::operator == (const IntegerSet& x) const
{

    if(a==x.a)
        return true;

    return false;

}
}

