#include "Triangular.h"



Triangular::Triangular(int i)
{
    set(1);
    gen_elems(i);


}

Triangular::~Triangular()
{
    clear();
}


void Triangular::gen_elems(int i)
{
    for(int j=length();j<=i-1;j++)
        set(get(j-1)+j+1);
}

