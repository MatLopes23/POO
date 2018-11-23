#include "Pentagonal.h"

Pentagonal::Pentagonal(int i)
{
    gen_elems(i);
}

Pentagonal::~Pentagonal()
{
    clear();
}


void Pentagonal::gen_elems(int i)
{
    for(int j=length();j<=i;j++)
        set((j+1)*(3*j+2)/2);
}

