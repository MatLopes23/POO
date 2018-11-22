#include "Lista_encadeada.h"
#include<iostream>
#include<fstream>

using namespace std;

Lista_encadeada::Link::Link(int d,Link *p)
{
    dado=d;
    prox=p;
}

Lista_encadeada::Link::~Link(){}

Lista_encadeada::Lista_encadeada()
{
    Lista=0;
}

Lista_encadeada::~Lista_encadeada()
{
    struct Link *aux;

    while(Lista!=0)///Percorre toda a lista para destruir cada nó separadamente
    {
        aux=Lista;
        Lista=Lista->prox;
        delete aux;
    }
}

void Lista_encadeada::inserir(const int d)
{
    struct Link *p,*x;

    if(Lista==0)/// Trata o caso da esta vazia
        Lista= new Link(d,Lista);

    else
    {
        p=Lista;

        while(p!=0)///O while vai percorre a lista procurando a posição para a inserção
        {
            if(p->dado==d)///Trata a repetição de elementos
                break;
            if(p->dado > d)///Condição para inserir elemetos na primeira posição
            {
                x=new Link(d,p);
                Lista=x;
                break;
            }
            if(p->prox==0 || p->prox->dado > d)///Condição para inserir elementos da segunda posição em diante
            {
                x=new Link(d,p->prox);
                p->prox=x;
                break;
            }

            p=p->prox;
        }
    }


}

int Lista_encadeada::procura(const int d)const ///Retorna a posição do elemento se ele estive contido na lista
{
    struct Link *p;
    int cont=0;

    p=Lista;

    while(p!=0)
    {
        if(p->dado==d)
            return cont;
        if(p->dado > d)
        {
            return -1;
        }
        cont++;
        p=p->prox;
    }
    return -1;

}

void Lista_encadeada::remover(const int d)
{
    struct Link *p, *aux;

    p=Lista;

    while(p!=0)///O while vai percorre a lista procurando a posição para a remoção
    {
        if(p->dado==d)///Condição para remover os elemetos na primeira posição
        {
            aux=Lista;
            Lista=Lista->prox;
            delete aux;
            break;
        }
        if(p->prox!=0 && p->prox->dado==d)///Condição para remover elementos da segunda posição em diante
        {
            aux=p->prox;
            p->prox=aux->prox;
            delete aux;
            break;
        }
        p=p->prox;
    }
}

void Lista_encadeada::imprimir()const
{
    struct Link *aux;

    aux=Lista;
     while(aux!=0)
    {
        cout<<aux->dado<<" ";
        aux=aux->prox;
    }
    cout<<endl<<endl;
}

void Lista_encadeada::LeDeArquivo(const string nomeArquivo)
{
    ifstream arq(nomeArquivo.c_str());
      int x;
      while(arq>>x)
          inserir(x);
}

void Lista_encadeada::GravarArquivo(const string nomeArquivo)
{
    ofstream out(nomeArquivo);

    struct Link *aux;

    aux=Lista;
     while(aux!=0)
    {
        out<<aux->dado<<" ";
        aux=aux->prox;
    }
}
