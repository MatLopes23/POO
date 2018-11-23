#include "Pell.h"


Pell::Pell(int i)
{
    set(1);
    set(2);
    gen_elems(i);


}

Pell::~Pell()
{
    clear();
}


void Pell::gen_elems(int i)
{
    for(int j=length();j<=i-1;j++)
        set(2*get(j-1)+get(j-2));
}

