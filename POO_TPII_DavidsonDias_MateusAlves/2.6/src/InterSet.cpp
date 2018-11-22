#include "InterSet.h"
#include<array>
#include<iostream>
#include<fstream>
#include<string>

using namespace std;

InterSet::InterSet()
{
    a.fill(false); /// Preenche as posições do array como 'false'
}

InterSet::~InterSet()
{
    //dtor
}

int InterSet::InsereElemento(const int k)///Retorno 1 se o elemento foi inserido e 0 caso o conjunto não supurte o elemento
{
    if(k>=0&&k<=100)///Restrição para o valor
       {
        a[k]= {true};
        return 1;
       }
        return 0;


}

int InterSet::RemoveElemento(const int k)///Retorno 1 se o elemento foi removido e 0 caso elemento não exista no conjunto
{
    if(k>=0&&k<=100) ///Restrição para o valor
    {
        if(a[k]==false)
            return 0;

        a[k]= {false};
        return 1;
    }
    return 0;
}

void InterSet::Uniao(const InterSet x,const InterSet y)
{
    for(int i=0; i<101; i++)
        a[i]=x.a[i]+y.a[i];

}

void InterSet::Intersecao(const InterSet x,const InterSet y)
{
    for(int i=0; i<101; i++)
        a[i]=x.a[i]*y.a[i];

}

void InterSet::Imprime() const
{
    int aux=0;

    for (int i = 0; i < 101; i++)
    {
        if(a[i]==true)
        {
            cout << i <<" ";
            aux++;
        }
    }
    if(aux==0)
        cout <<"---";
    cout <<endl;

}

int InterSet::Igual(const InterSet x) const
{
        if(a==x.a)
           return 1;

        return 0;
}

void InterSet::LeDeArquivo(const string nomeArquivo)
{
      ifstream arq(nomeArquivo.c_str());
      int x;
      while(arq>>x)
          InsereElemento(x);
 }


