#include <iostream>
#include <cstdlib>
#include <Seq.h>
#include <Fibonacci.h>
#include <Lucas.h>
#include <Pell.h>
#include <Triangular.h>
#include <Quadrados.h>
#include <Pentagonal.h>
#include <container.h>

using namespace std;

int main()
{
    container x;
    Seq *s;
    while(1)
    {
        char c;
        int i;
        system("cls");
        cout<<"Escolha a serie e forneça o parametro:\n"
            "A - Fibonacci\n"
            "B - Lucas\n"
            "C - Pell\n"
            "D - Triangular\n"
            "E - Quadrados\n"
            "F - Pentagonal\n"
            "G - Sair\n";
        cin>>c;
        if(c=='A')
        {
            cin>>i;
            Fibonacci f(i);
            cout<<f.length();
            cout<<f;

            Lucas L(i);
            cout<<L.length();
            cout<<L;
            cout<<f;
            system("pause");
            //s=new Fibonacci(i);
        }
        else if(c=='B')
        {
            cin>>i;
            //s=new Lucas(i);
        }
        else if(c=='C')
        {
            cin>>i;
            //s=new Pell(i);
        }
        else if(c=='D')
        {
            cin>>i;
            //s=new Triangular(i);
        }
        else if(c=='E')
        {
            cin>>i;
            //s=new Quadrados(i);
        }
        else if(c=='F')
        {
            cin>>i;
            //s=new Pentagonal(i);
        }
        else
            break;
        //x.set(s);
        //delete s;
    }
    //s->print(cout);
    //cout<<x;
    return 0;
}
