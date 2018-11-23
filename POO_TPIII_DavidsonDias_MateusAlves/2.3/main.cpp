#include <iostream>
#include<cstdio>
#include<Racional.h>

using namespace std;
using namespace Matematica;

int main()
{
    int a,b,c;
    Racional x,y,z;
    double d;


    cout<<"Digite o primeiro numero racional (n/d): \n";
    scanf("%d/%d",&a,&b);

    x.add(a,b);

    cout<<"Digite o segundo numero racional (n/d): \n";
    scanf("%d/%d",&a,&b);

    y.add(a,b);



    while(1)
    {
        cout<<"Selecione a operacao a ser usada nos numeros racionais: \n1-Somar\n2-Subtrair\n3-Multiplicar\n4-Dividir\n5-Converter double para racional\n6-Sair \n";
        cin>>c;

        if(c==1)
        {
            z=x+y;
            cout<<"Resultado:\n"<<z;

            z.printflutuante();
            cout<<"------------------------\n";
        }
        else if(c==2)
        {
            z=x-y;
            cout<<"Resultado:\n"<<z;

            z.printflutuante();
            cout<<"------------------------\n";
        }
        else if(c==3){
            z=x*y;
            cout<<"Resultado:\n"<<z;

            z.printflutuante();
            cout<<"------------------------\n";
        }
        else if(c==4){
            z=x/y;
            cout<<"Resultado:\n"<<z;

            z.printflutuante();
            cout<<"------------------------\n";
        }
        else if(c==5){

            cout<<"Insira o valor double: ";
            cin>>d;
            Racional h(d);
            cout<<"Resultado:\n"<<h;

            h.printflutuante();

            cout<<"------------------------\n";
        }
        else if(c==6)
            break;

    }

    return 0;
}
