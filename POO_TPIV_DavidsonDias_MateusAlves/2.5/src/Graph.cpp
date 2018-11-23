#include "Graph.h"
#include <iostream>


Graph::Graph(const int n):A(0)
{
    if(n<0)
        V=1;
    else
        V=n;
    for(int i=0; i<=V; i++)
    {
        DataStructures::List aux;
        Grafo.push_back(aux);
    }
}

Graph::~Graph()
{
    Grafo.clear();
}

bool Graph::insert(const Edge& E)
{
    if(!Grafo[E.get_inicio()].procura(E.get_fim()))
    {
        Grafo[E.get_inicio()]+=(E.get_fim());
        Grafo[E.get_fim()]+=(E.get_inicio());
        A++;
        return true;
    }
    return false;
}

bool Graph::remove(const Edge& E)
{
    if(Grafo[E.get_inicio()].procura(E.get_fim()))
    {
        Grafo[E.get_inicio()]-=(E.get_fim());
        Grafo[E.get_fim()]-=(E.get_inicio());
        A--;
        return true;

    }
    return false;
}

std::ostream& operator << (std::ostream& op, const Graph& h)
{
    for(int i=1; i<=h.V; i++)
        op<<i<<"->"<<h.Grafo[i];

    return op;
}

bool Graph::edge(const Edge& E)const
{
    return Grafo[E.get_inicio()].procura(E.get_fim());
}

int Graph::coonnectedComponents()const
{
    int *v,cont=0;
    v=new int [V+1];
    for(int i=0; i<=V; i++)
        v[i]=0;

    for(int i=1; i<=V; i++)
        if(v[i]==0)
        {
            DFS(v, i);
            cont++;
        }

     return cont;

}

void Graph::DFS(int *v, int s)const
{
    int i;
    v[s]=1;
    for(i=0; i<Grafo[s].size(); i++)
        if(v[Grafo[s](i)]==0)
            DFS(v, Grafo[s](i));

}


