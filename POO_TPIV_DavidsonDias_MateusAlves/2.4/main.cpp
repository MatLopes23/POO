#include <iostream>
#include<Racional.h>
#include<iterator>
#include<set>
#include<algorithm>
#include<fstream>

using namespace std;
using namespace Matematica;

///Function object
struct menor_maior
{
    bool operator () (const Racional& a, const Racional& b)const
    {
        double x,y;
        x=a;
        y=b;
        return x<y;
    }
};

struct maior_menor
{
    bool operator () (const Racional& a, const Racional& b)const
    {
        double x,y;
        x=a;
        y=b;
        return x>y;
    }
};


int main()
{
    int a,b,c;
    Racional x,y,z;
    double d;

    set<Racional,maior_menor> container_descre;
    set<Racional,menor_maior> container_cre;

    string nome;
    cout<<"Insira nome do arquivo: ";
    cin>>nome;
    ifstream arq(nome.c_str());

    istream_iterator<Racional> eos;
    istream_iterator<Racional> it(arq);

    cout<<"Forma de ordenamento, no set: \n1-Crescente\n2-Decrescente\n";
    cin>>c;

    if(c==1)
    {

        while(it!=eos)
        {
            container_cre.insert(*it);
            ++it;
        }
        ostream_iterator<Racional> out_it (cout," ");
        copy ( container_cre.begin(), container_cre.end(), out_it );
    }
    else
    {

        while(it!=eos)
        {
            container_descre.insert(*it);
            ++it;
        }
        ostream_iterator<Racional> out_it (cout," ");
        copy ( container_descre.begin(), container_descre.end(), out_it );
    }

    return 0;
}
