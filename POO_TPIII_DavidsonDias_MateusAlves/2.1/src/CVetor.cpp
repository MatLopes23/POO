#include "CVetor.h"
#include<iostream>

namespace DataStrutures{

CVetor::CVetor(const CVetor& h):tam(h.tam)
{
    vetor=new int[tam];

    for(int i=0; i<tam; i++)
        vetor[i]=h.vetor[i];

}

CVetor& CVetor::operator = (const CVetor& h)
{

    if(this==&h)
        return *this;

    delete [] vetor;
    tam=h.tam;
    vetor=new int[tam];
    for(int i=0; i<tam; i++)
        vetor[i]=h.vetor[i];

    return *this;

}

CVetor CVetor::operator + (const CVetor& h)const
{

    if(h.tam==tam)
    {
        CVetor aux(tam);

        for(int i=0; i<tam; i++)
            aux.vetor[i]=vetor[i]+h.vetor[i];

        return aux;
    }

    CVetor aux2;
    return aux2;

}

CVetor CVetor::operator - (const CVetor& h)const
{
    if(h.tam==tam)
    {
        CVetor aux(tam);

        for(int i=0; i<tam; i++)
            aux.vetor[i]=vetor[i]-h.vetor[i];

        return aux;
    }

    CVetor aux2;
    return aux2;
}

CVetor::CVetor(const int n)
{
    if(n<=0)
        tam=0;

    if(n>0)
    {
        tam=n;
        vetor=new int[n];

        for(int i=0; i<n; i++)
            vetor[i]=0;
    }
}

CVetor::~CVetor()
{
    if(tam!=0)
        delete [] vetor;
}

std::ostream& operator << (std::ostream& op, const CVetor& h)
{
    op<<h.tam<<std::endl;

    for(int i=0;i<h.tam;i++)
        op<<h.vetor[i]<<" ";
    op<<std::endl;
    return op;
}

std::istream& operator >> (std::istream& op, CVetor& h)
{
    if(h.tam==0)
        delete [] h.vetor;
    op>>h.tam;
    h.vetor=new int[h.tam];
    for(int i=0;i<h.tam;i++)
        op>>h.vetor[i];
    return op;
}

int& CVetor::operator () (const int i)const
{
    if(i< tam)
        return vetor[i];
}

int& CVetor::operator [] (const int i)const
{
    if(i< tam)
        return vetor[i];
}

int CVetor::escalar(const CVetor& h) const
{
     if(h.tam==tam)
    {
        int aux=0;

        for(int i=0; i<tam; i++)
            aux+=vetor[i]*h.vetor[i];

        return aux;
    }
}

CVetor CVetor::vetorial_3D(const CVetor& h) const
{

    if(h.tam==3 && tam==3)
    {
        CVetor aux(3);

        aux[0]=(vetor[1]*h.vetor[2])-(h.vetor[1]*vetor[2]);
        aux[1]=(vetor[2]*h.vetor[0])-(h.vetor[2]*vetor[0]);
        aux[2]=(vetor[0]*h.vetor[1])-(h.vetor[0]*vetor[1]);

        return aux;
    }

    CVetor aux;
    return aux;
}

}
