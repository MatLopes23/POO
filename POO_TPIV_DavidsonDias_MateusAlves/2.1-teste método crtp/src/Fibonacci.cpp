#include "Fibonacci.h"

std::vector<unsigned long int>* Fibonacci::Vet=new std::vector<unsigned long int>;

Fibonacci::Fibonacci(int i)
{
    V=returSeq();
    set(1);
    set(1);
    gen_elems(i);
}

Fibonacci::~Fibonacci()
{
   clear();
}

std::vector<unsigned long int>* Fibonacci::returSeq()
{
   /* std::vector<unsigned long int>* X;
    X=new std::vector<unsigned long int>;
    std::cout<<"xxx";*/
    return Vet;
}


void Fibonacci::gen_elems(int i)
{
    for(int j=length();j<=i;j++)
        set(get(j-1)+get(j-2));
}

