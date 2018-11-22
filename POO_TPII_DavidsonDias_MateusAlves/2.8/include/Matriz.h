#ifndef MATRIZ_H
#define MATRIZ_H
#include<string>
#include<vector>


class Matriz
{
    double **M;
    int linhas,colunas;
    void Alocar();/// metodo privado para alocação da Matriz dado o numero de linhas e colunas

    public:
        Matriz(const int l=0,const int c=0);
        Matriz(const std::string nomeArquivo);
        void grava(const std::string& filename)const;
        int soma(const Matriz x, const Matriz y);
        void multiplicavector(const Matriz m, const std::vector<double> vec);
        void inserir();
        void imprimir()const;
        int size_coluna() const;
        virtual ~Matriz();


};

#endif // MATRIZ_H
