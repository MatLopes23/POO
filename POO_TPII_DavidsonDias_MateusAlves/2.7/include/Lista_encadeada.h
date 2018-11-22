#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <string>


class Lista_encadeada
{
    struct Link{
        int dado;
        Link *prox;
        Link(int d,Link *p);
        ~Link();
    }* Lista;

    public:
        Lista_encadeada();
        virtual ~Lista_encadeada();
        void inserir(const int d);
        int procura(const int d)const;
        void remover(const int d);
        void imprimir()const;
        void LeDeArquivo(const std::string nomeArquivo);
        void GravarArquivo(const std::string nomeArquivo);

};

#endif // LISTA_ENCADEADA_H
