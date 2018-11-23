#include "Matriz.h"
#include<cstring>
#include<iostream>
#include<fstream>
#include<vector>

using namespace DataStrutures;

namespace Matematica{

void Matriz::Desalocar()
{
    for(int i=0; i<linhas; i++)
        delete[] M[i];///Percorre toda as linhas da matriz para desalocando os vetores representando as colunas
    delete[] M;/// Desaloca o vetor de ponteiros que representa as linhas
}

void Matriz::Alocar()
{
    M=new double*[linhas];/// alocação de um vetor de ponteiros de tamanho igual ao numero de linhas
    for(int i=0; i<linhas; i++)
        M[i]= new double[colunas];///alocando um vetor de doubles de tamanho igual ao numero de colunas

    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            M[i][j]=0;
}

Matriz::Matriz(const Matriz& h):linhas(h.linhas),colunas(h.colunas)
{
    Alocar();
    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            M[i][j]=h.M[i][j];
}

Matriz::Matriz(const int l,const int c)
{
    linhas=l;
    colunas=c;
    if(l!=0 && c!=0)///condição para que haja a alocação da matriz somente quando o numero de linhas e colunas
        ///for determinado pelo usuario ou por algum metodo.
        Alocar();
    std::cout<<"Construtor pelas linhas e colunas"<<std::endl;

}

Matriz& Matriz::operator >> (const std::string& nomeArquivo)
{
    std::ifstream arq(nomeArquivo.c_str());
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

    return *this;
}

Matriz::~Matriz()
{
    Desalocar();
    std::cout<<"Destrutor"<<std::endl;
}

Matriz& Matriz::operator << (const std::string& nomeArquivo)const
 {
    std::ofstream out(nomeArquivo.c_str());

    out << linhas << " ";
    out << colunas << std::endl;
    for(int i=0; i<linhas; i++)
    {
        for(int j=0; j<colunas; j++)
            out << M[i][j] <<" ";
        out <<std::endl;
    }
}

Matriz Matriz::operator+(const Matriz& h)const
{

    if(h.linhas==linhas && h.colunas==colunas)
    {
        Matriz aux(linhas,colunas);

        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                aux.M[i][j]=h.M[i][j]+M[i][j];

        return aux;
    }
    else
    {
        Matriz aux;
        return aux;
    }
}

Matriz Matriz::operator-(const Matriz& h)const
{
    if(h.linhas==linhas && h.colunas==colunas)
    {
        Matriz aux(linhas,colunas);

        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                aux.M[i][j]=M[i][j]-h.M[i][j];

        return aux;
    }
    else
    {
        Matriz aux;
        return aux;
    }
}

Matriz& Matriz::operator+=(const Matriz& h)
{
    if(h.linhas==linhas && h.colunas==colunas)
    {

        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                M[i][j]=h.M[i][j]+M[i][j];

        return *this;
    }


}

Matriz& Matriz::operator-=(const Matriz& h)
{
    if(h.linhas==linhas && h.colunas==colunas)
    {
        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                M[i][j]=M[i][j]-h.M[i][j];

        return *this;
    }
    else
    {
        Matriz aux;
        return aux;
    }

}

Matriz Matriz::operator*(const Matriz& h)const
{
    if(colunas==h.linhas)
    {
        Matriz aux(linhas,h.colunas);
        for(int i=0; i<linhas; i++)
            for(int j=0; j<h.colunas; j++)
                for(int k=0; k<colunas; k++)
                    aux.M[i][j]+=M[i][k]*h.M[k][j];

        return aux;
    }


}

Matriz& Matriz::operator*=(const Matriz& h)
{

    if(colunas==h.linhas)
    {
        Matriz aux(linhas,h.colunas);
        for(int i=0; i<linhas; i++)
            for(int j=0; j<h.colunas; j++)
                for(int k=0; k<colunas; k++)
                    aux.M[i][j]+=M[i][k]*h.M[k][j];

        *this =aux;
        return *this;
    }

}

Matriz Matriz::operator*(const std::vector<double>& vec)const
{
    if(colunas==vec.size())
    {
        Matriz aux(linhas,1);

        for(int i=0; i<linhas; i++)
        {
            for(int j=0; j<vec.size(); j++)
                aux.M[i][0]+=(M[i][j]*vec[j]);
        }
        return aux;
    }
}

CVetor Matriz::operator*(const CVetor& vet)const
{
    if(colunas==vet.size())
    {
        CVetor aux(vet.size());

        for(int i=0; i<vet.size(); i++)
        {
            for(int j=0; j<vet.size(); j++)
                aux[i]+=(M[i][j]*vet[j]);
        }
        return aux;
    }

}
Matriz& Matriz::operator*=(const CVetor& vet)
{
    if(linhas==vet.size())
    {
        Matriz aux(linhas,1);

        for(int i=0; i<linhas; i++)
        {
            for(int j=0; j<vet.size(); j++)
                aux.M[i][0]+=(M[i][j]*vet[j]);
        }
         *this =aux;
        return *this;
    }

}

Matriz& Matriz::operator*=(const std::vector<double>& vec)
{
    if(linhas==vec.size())
    {
        Matriz aux(linhas,1);

        for(int i=0; i<linhas; i++)
        {
            for(int j=0; j<vec.size(); j++)
                aux.M[i][0]+=(M[i][j]*vec[j]);
        }
         *this =aux;
        return *this;
    }

}

int Matriz::size_coluna() const
{
    return colunas;
}

Matriz& Matriz::operator=(const Matriz& b)
{
    if (this==&b)
        return *this;

    Desalocar();
    linhas=b.linhas;
    colunas=b.colunas;

    Alocar();

    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            M[i][j]=b.M[i][j];

    return *this;
}

double& Matriz::operator()(const int i,const int j)const
{
    if(i<linhas||j<colunas||i>0||j>0)
        return (M[i][j]);
}

std::ostream& operator << (std::ostream& op, const Matriz& h)
{

    op<< h.linhas<<" "<< h.colunas <<std::endl;

    for(int i=0; i<h.linhas; i++)
    {
        for(int j=0; j<h.colunas; j++)
            op<<h.M[i][j]<<" ";
        op<<std::endl;
    }
    return op;
}

std::istream& operator >> (std::istream& op, Matriz& h)
{
    h.Desalocar();

    op >> h.linhas;
    op >> h.colunas;
    h.Alocar();

    for(int i=0; i<h.linhas; i++)
        for(int j=0; j<h.colunas; j++)
            op>>h.M[i][j];

    return op;
}
}

