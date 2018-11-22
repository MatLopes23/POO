#include <iostream>
#include<cstdio>
#include<Racional.h>

using namespace std;

int main()
{
    int a,b,c;
    Racional x,y,z;

    cout<<"Digite o primeiro numero racional (n/d): \n";
    scanf("%d/%d",&a,&b);

    x.add(a,b);

    cout<<"Digite o segundo numero racional (n/d): \n";
    scanf("%d/%d",&a,&b);

    y.add(a,b);

    while(1)
    {
        cout<<"Selecione a operacao a ser usada nos numeros racionais: \n1-Subtrair\n2-Multiplicar\n3-dividir\n4-Sair \n";
        cin>>c;

        if(c==1)
        {
            z.subtrair(x,y);
            cout<<"Resultado:\n";
            z.print();

            z.printflutuante();
            cout<<"------------------------\n";
        }
        else if(c==2){
            z.multiplicar(x,y);
            cout<<"Resultado:\n";
            z.print();

            z.printflutuante();
            cout<<"------------------------\n";
        }
        else if(c==3){
            z.dividir(x,y);
            cout<<"Resultado:\n";
            z.print();

            z.printflutuante();
            cout<<"------------------------\n";
        }
        else if(c==4)
            break;

    }

    return 0;
}
