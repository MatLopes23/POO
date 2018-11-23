#include "Lista_encadeada.h"
#include<iostream>
#include<fstream>

using namespace std;
namespace DataStructures
{
Lista_encadeada::Lista_encadeada(const Lista_encadeada& h)
{
    struct Link *aux;
    aux=h.Lista;
    Lista=0;
    while(aux!=0)
    {
        *this+=aux->dado;
        aux=aux->prox;
    }

}

Lista_encadeada& Lista_encadeada::operator = (const Lista_encadeada& h)
{

    if(this==&h)
        return *this;

    struct Link *aux;

    while(Lista!=0)///Percorre toda a lista para destruir cada nó separadamente
    {
        aux=Lista;
        Lista=Lista->prox;
        delete aux;
    }


    aux=h.Lista;
    while(aux!=0)
    {
        *this+=aux->dado;
        aux=aux->prox;
    }

    return *this;

}

Lista_encadeada::Link::Link(int d,Link *p)
{
    dado=d;
    prox=p;
}

Lista_encadeada::Link::~Link() {}

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

Lista_encadeada& Lista_encadeada::operator += (const Lista_encadeada& h)
{
    struct Link *aux;
    aux=h.Lista;

    while(aux!=0)
    {
        *this+=aux->dado;
        aux=aux->prox;
    }

    return *this;

}


Lista_encadeada Lista_encadeada::operator + (const Lista_encadeada& h) const
{
    Lista_encadeada obj;
    struct Link *aux,*aux2;
    aux=h.Lista;
    aux2=Lista;
    while(aux!=0)
    {
        obj+=aux->dado;
        aux=aux->prox;
    }
    while(aux2!=0)
    {
        obj+=aux2->dado;
        aux2=aux2->prox;
    }

    return obj;
}

Lista_encadeada& Lista_encadeada::operator +=(const int d)
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

    return *this;
}

Lista_encadeada& Lista_encadeada::operator -= (const int d)
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
    return *this;
}


void Lista_encadeada::LeDeArquivo(const string& nomeArquivo)
{
    ifstream arq(nomeArquivo.c_str());
    int x;
    while(arq>>x)
        *this+=x;
}

void Lista_encadeada::GravarArquivo(const string& nomeArquivo)
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

int Lista_encadeada::operator () (const int i)
{
    struct Link *aux;
    int cont=i;

    aux=Lista;

    while(aux!=0)///O while vai percorre a lista procurando a posição
    {
        if(cont==0)
            return aux->dado;

        aux=aux->prox;
        cont--;

    }

}

ostream& operator << (ostream& op, const Lista_encadeada& h)
{

    Lista_encadeada::Link *aux;

    aux=h.Lista;
    while(aux!=0)
    {
        op<<aux->dado<<" ";
        aux=aux->prox;
    }
    op<<endl;
    return op;
}

istream& operator >> (istream& op, Lista_encadeada& h)
{
    int aux;

    op>>aux;
    h+=aux;

    return op;
}


int Lista_encadeada::size()const/// Função auxiliar para a existencia de uma posição
{
    struct Link *aux;
    int tam=0;

    aux=Lista;
    while(aux!=0)
    {
        tam++;
        aux=aux->prox;
    }
    return tam;
}

}
