#ifndef INTEGERSET_H
#define INTEGERSET_H
#include<array>
#include<iostream>

namespace Matematica
{
class IntegerSet
{
    std::array<bool,101> a;

public:
    IntegerSet();
    virtual ~IntegerSet();
    IntegerSet operator + (const IntegerSet& )const;
    IntegerSet operator & (const IntegerSet& )const;
    IntegerSet& operator += (const int );
    IntegerSet& operator -= (const int );
    IntegerSet& operator >> (const std::string& nomeArquivo);
    friend std::ostream& operator << (std::ostream& op, const IntegerSet&);
    friend std::istream& operator >> (std::istream& op, IntegerSet&);
    bool operator == (const IntegerSet& x) const;

};
}

#endif // INTEGERSET_H
