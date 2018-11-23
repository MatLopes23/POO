#include "Seq.h"



Seq::Seq()
{
    //ctor
}

Seq::~Seq()
{
    //dtor
}
void Seq::print(std::ostream& os)
{
    for(int i=0; i<length(); i++)
        os<<V[i]<<", ";
    os<<std::endl;
}

int Seq::length()
{
    return V.size();
}

unsigned long int Seq::elem(int i)
{
    if(length()<=i)
        gen_elems(i);

    return V[i];

}

std::ostream& operator <<(std::ostream& op,Seq& h)
{
    h.print(op);

    return op;
}

void Seq::imprimi(int i,int j)
{
    if(i==-1||j==-1)
        std::cout<<(*this);
    else if(length()<=j)
    {
        gen_elems(j);
        for(int x=i; x<=j; x++)
            std::cout<<V[x]<<", ";
    }
}

void Seq::set (unsigned long int i)
{
    V.push_back(i);
}

unsigned long int Seq::get (unsigned long int i)
{
    return V[i];
}

void Seq::clear ()
{
    V.clear();
}
