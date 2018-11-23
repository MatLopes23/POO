#include "Lucas.h"


Lucas::Lucas(int i)
{
    set(1);
    set(3);
    gen_elems(i);


}

Lucas::~Lucas()
{
    clear();
}


void Lucas::gen_elems(int i)
{
    for(int j=length();j<=i-1;j++)
        set(get(j-1)+get(j-2));
}

