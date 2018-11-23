#ifndef LISTA_ENCADEADA_H
#define LISTA_ENCADEADA_H
#include <string>

namespace DataStructures{
class Lista_encadeada
{
    struct Link{
        int dado;
        Link *prox;
        Link(int d,Link *p);
        ~Link();
    };
    struct Link *Lista;

    public:

        Lista_encadeada(const Lista_encadeada& h);
        Lista_encadeada& operator = (const Lista_encadeada& );
        Lista_encadeada operator + (const Lista_encadeada& ) const;
        Lista_encadeada& operator += (const Lista_encadeada& );
        Lista_encadeada& operator +=(const int d);
        Lista_encadeada& operator -= (const int d);
        int operator () (const int );
        int size()const;
        Lista_encadeada();
        virtual ~Lista_encadeada();
        void LeDeArquivo(const std::string& nomeArquivo);
        void GravarArquivo(const std::string& nomeArquivo);

        friend std::ostream& operator << (std::ostream& op, const Lista_encadeada& h);
        friend std::istream& operator >> (std::istream& op, Lista_encadeada&);

};
}

#endif // LISTA_ENCADEADA_H

