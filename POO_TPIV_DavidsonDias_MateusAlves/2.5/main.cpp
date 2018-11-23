#include <iostream>
#include <Graph.h>
#include <cstdlib>

using namespace std;

int main()
{
    int x,y,z,aux=0;

    cout<<"Digite a quantidade de vertices do grafo: ";
    cin>>x;
    Graph g(x);
    Edge A;

    while(1)
    {
        system("cls");
      cout<<"1-inserir aresta\n"
            "2-remover aresta\n"
            "3-numero de vertices e arestas\n"
            "4-verificar existencia de aresta\n"
            "5-quantidade de subgrafos\n"
            "6-imprimir grafo\n"
            "7-sair\n";

        cin>>x;
        if(x==1)
        {
            cin>>y>>z;
            A.set(y,z);
            if(!g.insert(A))
                cout<<"Erro para inserir aresta\n";
        }
        else if(x==2)
        {
            cin>>y>>z;
            A.set(y,z);
            if(!g.remove(A))
                cout<<"Erro para remover aresta\n";
            system("pause");
        }
        else if(x==3)
        {
            cout<<"Vertices: "<<g.get_vertices()<<endl;
            cout<<"Arestas: "<<g.get_arestas()<<endl;
            system("pause");
        }
        else if(x==4)
        {
            cin>>y>>z;
            A.set(y,z);
            if(g.edge(A))
                cout<<"A aresta existe no grafo\n";
            else
                cout<<"A aresta nao existe no grafo\n";
            system("pause");
        }
        else if(x==5)
        {
            aux=g.coonnectedComponents();
            cout<<"Contem "<<aux<<" subgrafo(s).\n";
            system("pause");
        }
        else if(x==6)
        {
            cout<<g;
            system("pause");
        }
        else if(x==7)
            break;
    }



    return 0;
}
