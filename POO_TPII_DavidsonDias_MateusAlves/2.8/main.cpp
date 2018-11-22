#include <iostream>
#include <Matriz.h>
#include <string>
#include <vector>

using namespace std;

int main()
{
    Matriz *m, *m2;///Declarado como ponteiro para que possam ser inicializados de formas da escolhida pelo usuário
    Matriz rm;
    int l,c,x,y;
    string nome;

    cout<<"Insira o metodo para criar uma matriz:\n"
          "1-Ler de arquivo.\n"
          "2-Inserir manualmente\n";

    cin>>x;
    if(x==1)
    {
        cout<<"Nome do Arquivo: ";
        cin>>nome;
        m=new Matriz(nome);
    }
    else if(x==2)
    {
        cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
        cin>>l;
        cin>>c;
        m=new Matriz(l, c);
        m->inserir();
    }

    cout<<"Operacao:\n"
        "1-Gravar matriz em disco.\n"
        "2-Somar duas matrizes.\n"
        "3-Multiplicar por um vetor."<<endl;

    cin>>x;
    if(x==1)
    {
        cout<<"Nome e extesao do arquivo a ser gerando: ";
        cin>>nome;
        m->grava(nome);
    }
    else if(x==2)
    {

        cout<<"Forneca a nova matriz para ser somada, escolha o metodo para ler a nova matriz:"
              "1-Ler de arquivo.\n"
              "2-Inserir manualmente\n";

        cin>>y;
        if(y==1)
        {
            cout<<"Nome do Arquivo: ";
            cin>>nome;
            m2=new Matriz(nome);
        }
        else if(y==2)
        {
            cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
            cin>>l;
            cin>>c;
            m2=new Matriz(l, c);;
            m2->inserir();
        }
        if(!rm.soma(*m, *m2))
            cout<<"Nao foi possivel realizar essa operacao.\n";

    }
    else if(x==3)
    {
        vector<double> vec;
        cout<<"Forneca o vetor (de tamanho "<<m->size_coluna()<<"): ";
        for(int i=0;i<m->size_coluna();i++)///criada função size_coluna para retornar o numedo de colunas
                                          /// para armazenar o tamanho necessario de um vector
        {
            cin>>y;
            vec.push_back(y);
        }
        rm.multiplicavector(*m, vec);
    }
    cout<<"Matriz Resultante:"<<endl;
    rm.imprimir();
    cout<<endl;
    return 0;
}
