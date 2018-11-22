#include "Matriz.h"
#include<new>
#include<cstring>
#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

void Matriz::Alocar()
{
    M=new double*[linhas];/// alocação de um vetor de ponteiros de tamanho igual ao numero de linhas
    for(int i=0; i<linhas; i++)
        M[i]= new double[colunas];///alocando um vetor de doubles de tamanho igual ao numero de colunas

    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            M[i][j]=0;
}

Matriz::Matriz(const int l,const int c)
{
    linhas=l;
    colunas=c;
    if(l!=0 && c!=0)///condição para que haja a alocação da matriz somente quando o numero de linhas e colunas
                    ///for determinado pelo usuario ou por algum metodo.
        Alocar();
    cout<<"Construtor pelas linhas e colunas"<<endl;

}

Matriz::Matriz(const string nomeArquivo)
{
    ifstream arq(nomeArquivo.c_str());
    double x;

    /// x irá receber os tamanhos de linhas e colunas do inicio do arquivo
    arq>>x;
    linhas=x;
    arq>>x;
    colunas=x;
    Alocar();

    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            if(arq>>x)
                M[i][j]=x;

    cout<<"Construtor pela String"<<endl;
}

Matriz::~Matriz()
{
    for(int i=0; i<linhas; i++)
        delete[] M[i];///Percorre toda as linhas da matriz para desalocando os vetores representando as colunas

    delete[] M;/// Desaloca o vetor de ponteiros que representa as linhas
    cout<<"Destrutor"<<endl;
}

void Matriz::grava(const string& filename) const
{
    ofstream out(filename.c_str());

    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++)
            out << M[i][j] <<" ";
        out <<endl;
    }

}

int Matriz::soma(const Matriz x, const Matriz y)
{
    if(x.linhas==y.linhas && x.colunas==y.colunas)
    {
        linhas=x.linhas;
        colunas=x.colunas;
        Alocar();/// aloca uma matriz para receber a soma das duas outras matrizes

        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                M[i][j]=x.M[i][j]+y.M[i][j];

        return 1;
    }
    else
        return 0;
}

void Matriz::multiplicavector(const Matriz m, const vector<double> vec)
{
    linhas=m.linhas;
    colunas=1;
    Alocar();/// aloca uma matriz para receber a multiplicaçao entre um vector e uma matriz

    for(int i=0; i<m.linhas; i++)
    {
        for(int j=0; j<vec.size(); j++)
            M[i][0]+=(m.M[i][j]*vec[j]);
    }
}

void Matriz::imprimir() const
{
    for(int i=0; i<linhas; i++){
        for(int j=0; j<colunas; j++)
            cout<<M[i][j]<<" ";
        cout<<endl;
    }
}
void Matriz::inserir()
{
    int x;
    for(int i=0;i<linhas;i++)
        for(int j=0;j<colunas;j++)
            cin>>M[i][j];
}

int Matriz::size_coluna() const
{
    return colunas;
}
