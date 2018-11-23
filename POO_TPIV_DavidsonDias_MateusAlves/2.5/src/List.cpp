#include "List.h"
#include<iostream>
#include<fstream>

using namespace std;
namespace DataStructures
{
List::List(const List& h)
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

List& List::operator = (const List& h)
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

List::Link::Link(int d,Link *p)
{
    dado=d;
    prox=p;
}

List::Link::~Link() {}

List::List()
{
    Lista=0;
}

List::~List()
{
    struct Link *aux;

    while(Lista!=0)///Percorre toda a lista para destruir cada nó separadamente
    {
        aux=Lista;
        Lista=Lista->prox;
        delete aux;
    }
}

List& List::operator += (const List& h)
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


List List::operator + (const List& h) const
{
    List obj;
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

List& List::operator +=(const int d)
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

List& List::operator -= (const int d)
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


void List::LeDeArquivo(const string& nomeArquivo)
{
    ifstream arq(nomeArquivo.c_str());
    int x;
    while(arq>>x)
        *this+=x;
}

void List::GravarArquivo(const string& nomeArquivo)
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

int List::operator () (const int i)const
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

ostream& operator << (ostream& op, const List& h)
{

    List::Link *aux;

    aux=h.Lista;
    while(aux!=0)
    {
        op<<aux->dado<<" ";
        aux=aux->prox;
    }
    op<<endl;
    return op;
}

istream& operator >> (istream& op, List& h)
{
    int aux;

    op>>aux;
    h+=aux;

    return op;
}


int List::size()const/// Função auxiliar para a existencia de uma posição
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
bool List::procura(const int d)const ///Retorna a posição do elemento se ele estive contido na lista
{
    struct Link *p;

    p=Lista;

    while(p!=0)
    {
        if(p->dado==d)
            return true;
        if(p->dado > d)
        {
            return false;
        }
        p=p->prox;
    }
    return false;

}

}

