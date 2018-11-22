#ifndef INTERSET_H
#define INTERSET_H
#include<array>


class InterSet
{
    std::array<bool,101> a;

    public:
        InterSet();
        virtual ~InterSet();
        int InsereElemento(const int k);
        int RemoveElemento(const int k);
        void Uniao(const InterSet x,const InterSet y);
        void Intersecao(const InterSet x,const InterSet y);
        void Imprime() const ;
        int Igual(const InterSet x) const;
        void LeDeArquivo(const std::string nomeArquivo);

};

#endif // INTERSET_H
