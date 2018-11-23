#ifndef MATRIZ_H
#define MATRIZ_H
#include<string>
#include<vector>
#include<iostream>
#include<CVetor.h>


namespace Matematica{
class Matriz
{

    double **M;
    int linhas,colunas;
    void Alocar();/// metodo privado para alocação da Matriz dado o numero de linhas e colunas
    void Desalocar();/// metodo privado para desalocação da Matriz

    public:

        Matriz(const Matriz& h);
        Matriz(const int l=0,const int c=0);
        Matriz& operator=(const Matriz& );
        Matriz operator+(const Matriz& )const;
        Matriz operator-(const Matriz& )const;
        Matriz& operator+=(const Matriz& );
        Matriz& operator-=(const Matriz& );
        Matriz operator*(const Matriz& )const;
        Matriz& operator*=(const Matriz& );
        Matriz operator*(const std::vector<double>& )const;
        DataStrutures::CVetor operator*(const DataStrutures::CVetor& vet)const;
        Matriz& operator*=(const DataStrutures::CVetor& vet);
        Matriz& operator*=(const std::vector<double>& );
        double& operator()(const int i,const int j)const;
        Matriz& operator >> (const std::string& nomeArquivo);
        Matriz& operator << (const std::string& nomeArquivo)const;

        friend std::ostream& operator << (std::ostream& op, const Matriz&);
        friend std::istream& operator >> (std::istream& op,  Matriz&);

        int size_coluna() const;
        virtual ~Matriz();


};
}

#endif // MATRIZ_H
