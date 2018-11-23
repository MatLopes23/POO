#include "Lucas.h"

std::vector<unsigned long int>* Lucas::Vet=new std::vector<unsigned long int>;

Lucas::Lucas(int i)
{
    V=returSeq();
    set(1);
    set(3);
    gen_elems(i);


}

Lucas::~Lucas()
{
    clear();
}

std::vector<unsigned long int>* Lucas::returSeq()
{
   /* std::vector<unsigned long int>* X;
    X=new std::vector<unsigned long int>;*/
    return Vet;
}

void Lucas::gen_elems(int i)
{
    for(int j=length();j<=i;j++)
        set(get(j-1)+get(j-2));
}

