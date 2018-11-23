#include "Fibonacci.h"

Fibonacci::Fibonacci(int i)
{
    set(1);
    set(1);
    gen_elems(i);
}

Fibonacci::~Fibonacci()
{
   clear();
}


void Fibonacci::gen_elems(int i)
{
    for(int j=length();j<=i-1;j++)
        set(get(j-1)+get(j-2));
}

