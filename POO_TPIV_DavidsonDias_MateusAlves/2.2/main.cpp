#include <iostream>
#include <Matriz.h>
#include <string>
#include <vector>

using namespace Matematica;


using std::cin;
using std::cout;
using std::endl;



int main()
{
    Matriz<char> *m, *m2;///Declarado como ponteiro para que possam ser inicializados de formas da escolhida pelo usuário
    Matriz<char> rm;

    int l,c,x,y;
    std::string nome;

    cout<<"Insira o metodo para criar uma matriz:\n"
        "1-Ler de arquivo.\n"
        "2-Inserir manualmente\n";

    cin>>x;
    if(x==1)
    {
        cout<<"Nome do Arquivo: ";
        cin>>nome;
        m=new Matriz<char>;
        *m>>nome;
    }
    else if(x==2)
    {
        cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
        m=new Matriz<char>;
        cin>> *m;
    }

    cout<<"Operacao:\n"
        "1-Gravar matriz em disco.\n"
        "2-Somar duas matrizes.\n"
        "3-Subtrair duas matrizes.\n"
        "4-Atribuir a segunda matriz na primeira(+=).\n"
        "5-Subtrair a segunda matriz na primeira(-=).\n"
        "6-Multiplicar duas matrizes.\n"
        "7-Multiplicar a segunda matriz na primeira(*=).\n"
        "8-Multiplicar por um vector.\n"<<endl;

    cin>>x;
    if(x==1)
    {
        cout<<"Nome e extesao do arquivo a ser gerando: ";
        cin>>nome;
        *m<<nome;
    }
    else if(x==2)
    {

        cout<<"Forneca a nova matriz para ser somada, escolha o metodo para ler a nova matriz:\n"
            "1-Ler de arquivo.\n"
            "2-Inserir manualmente\n";

        cin>>y;
        if(y==1)
        {
            cout<<"Nome do Arquivo: ";
            cin>>nome;
            m2=new Matriz<char>;
            *m2>>nome;
        }
        else if(y==2)
        {
            cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
            m2=new Matriz<char>;
            cin>> *m2;
        }
        rm=*m+*m2;
        cout<<"Matriz Resultante:"<<endl;
        cout<<rm;
    }
    else if(x==3)
    {
        cout<<"Forneca a nova matriz para ser subtraida, escolha o metodo para ler a nova matriz:\n"
            "1-Ler de arquivo.\n"
            "2-Inserir manualmente\n";

        cin>>y;
        if(y==1)
        {
            cout<<"Nome do Arquivo: ";
            cin>>nome;
            m2=new Matriz<char>;
            *m2>>nome;
        }
        else if(y==2)
        {
            cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
            m2=new Matriz<char>;
            cin>> *m2;
        }
        rm=*m-*m2;
        cout<<"Matriz Resultante:"<<endl;
        cout<<rm;

    }
    else if(x==4)
    {
        cout<<"Forneca a nova matriz para ser atribuida na primeira matriz, escolha o metodo para ler a nova matriz:\n"
            "1-Ler de arquivo.\n"
            "2-Inserir manualmente\n";

        cin>>y;
        if(y==1)
        {
            cout<<"Nome do Arquivo: ";
            cin>>nome;
            m2=new Matriz<char>;
            *m2>>nome;
        }
        else if(y==2)
        {
            cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
            m2=new Matriz<char>;
            cin>> *m2;
        }
        *m+=*m2;
        cout<<"Matriz Resultante:"<<endl;
        cout<<*m;
    }
    else if(x==5)
    {
        cout<<"Forneca a nova matriz para ser subtraida na primeira matriz, escolha o metodo para ler a nova matriz:\n"
            "1-Ler de arquivo.\n"
            "2-Inserir manualmente\n";

        cin>>y;
        if(y==1)
        {
            cout<<"Nome do Arquivo: ";
            cin>>nome;
            m2=new Matriz<char>;
            *m2>>nome;
        }
        else if(y==2)
        {
            cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
            m2=new Matriz<char>;
            cin>> *m2;
        }
        *m-=*m2;
        cout<<"Matriz Resultante:"<<endl;
        cout<<*m;
    }
    else if(x==6)
    {

        cout<<"Forneca a nova matriz para ser multiplicada, escolha o metodo para ler a nova matriz:\n"
            "1-Ler de arquivo.\n"
            "2-Inserir manualmente\n";

        cin>>y;
        if(y==1)
        {
            cout<<"Nome do Arquivo: ";
            cin>>nome;
            m2=new Matriz<char>;
            *m2>>nome;
        }
        else if(y==2)
        {
            cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
            m2=new Matriz<char>;
            cin>> *m2;
        }
        rm=(*m)*(*m2);
        cout<<"Matriz Resultante:"<<endl;
        cout<<rm;
    }
    else if(x==7)
    {
        cout<<"Forneca a nova matriz para ser multiplicada na primeira matriz, escolha o metodo para ler a nova matriz:\n"
            "1-Ler de arquivo.\n"
            "2-Inserir manualmente\n";

        cin>>y;
        if(y==1)
        {
            cout<<"Nome do Arquivo: ";
            cin>>nome;
            m2=new Matriz<char>;
            *m2>>nome;
        }
        else if(y==2)
        {
            cout<<"Numero de linhas e colunas da matriz seguido dos valores:\n";
            m2=new Matriz<char>;
            cin>> *m2;
        }
        (*m)*=*m2;
        cout<<"Matriz Resultante:"<<endl;
        cout<<*m;
    }
    else if(x==8)
    {
        int z;
        std::vector<char> vec;
        cout<<"Forneca o vector (de tamanho "<<m->size_coluna()<<"): ";
        for(int i=0; i<m->size_coluna(); i++) ///criada função size_coluna para retornar o numedo de colunas
            /// para armazenar o tamanho necessario de um vector
        {
            cin>>y;
            vec.push_back(y);
        }
        cout<<"Armazenar na mesma matriz:\n1-sim\n2-nao\n";
        cin>>z;
        if(z=1)
        {
            (*m)*=vec;
            cout<<"Matriz Resultante:"<<endl;
            cout<<*m;
        }
        else
        {
            rm=(*m)*vec;
            cout<<"Matriz Resultante:"<<endl;
            cout<<rm;
        }
    }

    ///Teste da função global
    {
        Matriz<char>::iterator it=(*m).begin();
        Matriz<char>::iterator it2=(*m).begin();
        Matriz<char>::iterator it3=(*m).begin();
        it++;
        it3=it_maior(it, it2);
        cout<<"it: "<<*it<<endl;
        cout<<"it2: "<<*it2<<endl;
        cout<<"it3: "<<*it3<<endl;

    }

    return 0;
}
