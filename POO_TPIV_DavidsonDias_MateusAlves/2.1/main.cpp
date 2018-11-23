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
            "H - Imprimir sequencias acumuladas\n"
            "I - Sair\n";
        cin>>c;
        if(c=='A')
        {
            cin>>i;
            s=new Fibonacci(i);
            x.set(s);
        }
        else if(c=='B')
        {
            cin>>i;
            s=new Lucas(i);
            x.set(s);
        }
        else if(c=='C')
        {
            cin>>i;
            s=new Pell(i);
            x.set(s);
        }
        else if(c=='D')
        {
            cin>>i;
            s=new Triangular(i);
            x.set(s);
        }
        else if(c=='E')
        {
            cin>>i;
            s=new Quadrados(i);
            x.set(s);
        }
        else if(c=='F')
        {
            cin>>i;
            s=new Pentagonal(i);
            x.set(s);
        }
        else if(c=='H')
            cout<<x;
        else if(c=='I')
            break;

        system("pause");
    }
    cout<<x;
    return 0;
}
