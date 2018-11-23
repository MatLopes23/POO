#ifndef RACIONAL_H
#define RACIONAL_H
#include<iostream>

namespace Matematica
{
class Racional
{
private:
    int numerador,denominador;
    void simplificar(int n,int d);

public:
    Racional(const int n=0, int d=1);
    Racional(const double d);
    virtual ~Racional();
    void add(const int n, int d=1);///O denominador por default recebe 1 para caso ele não seja especificado
    Racional operator - (const Racional& )const;
    Racional operator + (const Racional& )const;
    Racional operator * (const Racional& )const;
    Racional operator / (const Racional& )const;

    operator double()const;

    friend std::ostream& operator << (std::ostream& op, const Racional&);
    friend std::istream& operator >> (std::istream& op, Racional&);

    void printflutuante()const ;


};

inline Racional::operator double()const
{
    return (double)numerador/denominador;
};
}
#endif // RACIONAL_H
