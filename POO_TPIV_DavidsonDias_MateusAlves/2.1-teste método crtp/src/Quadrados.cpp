#include "Quadrados.h"

Quadrados::Quadrados(int i)
{
    gen_elems(i);
}

Quadrados::~Quadrados()
{
    clear();
}


void Quadrados::gen_elems(int i)
{
    for(int j=length();j<=i;j++)
        set((j+1)*(j+1));
}

