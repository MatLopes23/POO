#ifndef CVETOR_H
#define CVETOR_H
#include<iostream>

namespace DataStrutures
{
class CVetor
{
    int *vetor,tam;

public:
    CVetor(const CVetor& h);
    CVetor(const int n=1);
    virtual ~CVetor();
    CVetor& operator = (const CVetor& h);
    CVetor operator + (const CVetor& h)const;
    CVetor operator - (const CVetor& h)const;
    int& operator [] (const int)const;
    int& operator () (const int)const;
    int escalar(const CVetor&) const;
    CVetor vetorial_3D(const CVetor&) const;

    friend std::ostream& operator << (std::ostream& op, const CVetor& h);
    friend std::istream& operator >> (std::istream& op, CVetor& h);


};
}



#endif // CVETOR_H
