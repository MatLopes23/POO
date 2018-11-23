#include <iostream>
#include<cstdlib>
#include "CVetor.h"

using namespace std;
using namespace DataStrutures;

int main()
{

    CVetor A, B, C;
    cout<<"----CVetor----"<<endl;
    cout<<"Digite o vetor (tamanho valores): \n";
    cin>>A;


    while(1)
    {
        system("cls");


        int x;
        cout<<"1-Alterar um valor do vetor.\n"
            "2-Acessar posicao.\n"
            "3-Somar dois vetores.\n"
            "4-Subtrair dois vetores.\n"
            "5-Produto escalar.\n"
            "6-Produto vetorial(3 dimensoes).\n"
            "7-Sair.\n";
        cin>>x;
        if(x==1)
        {
            int aux,aux2;
            cout<<"Posicao e novo valor: ";
            cin>>aux;
            cin>>aux2;
            A[aux-1]=aux2;

            cout<<"Vetor resultante:\n"<<A;
        }
        else if(x==2)
        {
            int aux;
            cout<<"Posicao: ";
            cin>>aux;
            cout<<A[aux-1]<<endl;
        }
        else if(x==3)
        {
            cout<<"Digite o segundo vetor (tamanho valores): \n";
            cin>>B;

            C=A+B;
            cout<<"Vetor resultante:\n"<<C;

        }
        else if(x==4)
        {
            cout<<"Digite o segundo vetor (tamanho valores): \n";
            cin>>B;

            C=A-B;
            cout<<"Vetor resultante:\n"<<C;
        }
        else if(x==5)
        {
            int aux;
            cout<<"Digite o segundo vetor (tamanho valores): \n";
            cin>>B;

            aux=A.escalar(B);
            cout<<"Produto escalar: "<<aux<<endl;
        }
        else if(x==6)
        {
            cout<<"Digite o segundo vetor (tamanho valores): \n";
            cin>>B;

            C=A.vetorial_3D(B);
            cout<<"Produto vetorial:\n"<<C;
        }
        else if(x==7)
            break;


       system("pause");
    }


    return 0;
}
