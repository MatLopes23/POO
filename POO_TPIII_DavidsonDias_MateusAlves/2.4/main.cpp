#include <iostream>
#include<IntegerSet.h>
#include<vector>
#include<stdlib.h>

using namespace Matematica;
using namespace std;

int main ()
{
    vector <IntegerSet> Conjuntos;
    int num, x;

    cout<<"Digite a quantidade de conjuntos com elementos entre 0 e 100: ";
    cin>>num;

    cout<<"\nDeseja ler conjuntos de arquivos:\n1-Sim\n2-Nao"<<endl;
    cin>>x;
    if(x==1)
        for(int i=1; i<=num; i++)
        {
            string nomeArquivo;
            IntegerSet obj;
            Conjuntos.push_back(obj);
            cout<<"Nome do arquivo: "<<endl;
            cin>>nomeArquivo;
            Conjuntos[i-1]>>nomeArquivo;
        }
    else if(x==2)
    {

        cout<<"\nObs: Para encerrar a insercao de elementos no conjunto digite um numero negativo"<<endl;

        for(int i=1; i<=num; i++)
        {
            IntegerSet obj;
            Conjuntos.push_back(obj);
            cout<<"Elementos do conjunto "<<i<<" : "<<endl;
            while(1)
            {
                int aux;
                cin>>aux;
                if(aux<0)
                    break;
                Conjuntos[i-1]+=aux;
            }
        }
    }


    while(1)
    {
        system("cls");
        cout<<"Escolha a operacao a ser realizada nos conjuntos:\n"
            "1-Inserir elemento em um conjunto.\n"
            "2-Remover elemento de um conjunto.\n"
            "3-Uniao de dois conjuntos.\n"
            "4-Intersecao de dois conjuntos.\n"
            "5-Verificar se dois conjuntos sao iguais.\n"
            "6-Imprimir Conjunto.\n"
            "7-Sair.\n"
            "--------------------------------------------------------\n";
        cin>>x;


        if(x==1)
        {
            cout<<"Escolha o Conjunto e o elemento a ser inserido (separado por espaco):\n";
            int conj;
            cin>> conj;
            cin>>Conjuntos[conj-1];

        }
        else if(x==2)
        {
            cout<<"Escolha o Conjunto e o elemento a ser removido (separado por espaco):\n";
            int conj, elemento;
            cin>> conj;
            cin>> elemento;
            Conjuntos[conj-1]-=elemento;

        }
        else if(x==3)
        {
            cout<<"Escolha os dois Conjuntos para fazer a uniao (separado por espaco):"<<endl;
            int c1, c2;
            IntegerSet novo;
            cin>> c1;
            cin>> c2;
            novo=(Conjuntos[c1-1]+Conjuntos[c2-1]);
            Conjuntos.push_back(novo);
            cout<<"O conjunto "<< Conjuntos.size() <<" contem a Uniao de "<< c1 << " e " << c2 << "."<<endl;
        }
        else if(x==4)
        {
            cout<<"Escolha os dois Conjuntos para fazer a intersecao (separado por espaco):"<<endl;
            int c1, c2;
            IntegerSet novo;
            cin>> c1;
            cin>> c2;
            novo=(Conjuntos[c1-1]&Conjuntos[c2-1]);
            Conjuntos.push_back(novo);
            cout<<"O conjunto "<< Conjuntos.size() <<" contem a Intersecao de "<< c1 << " e " << c2 << "."<<endl;
        }
        else if(x==5)
        {
            int c1, c2;
            cout<<"Escolha os dois Conjuntos para verificar se soa iguais (separado por espaco):"<<endl;
            cin>> c1;
            cin>> c2;
            if(Conjuntos[c1-1]==(Conjuntos[c2-1]))
                cout<<"Conjuntos iguais"<<endl;
            else
                cout<<"Conjuntos diferentes"<<endl;
        }
        else if(x==6)
        {
            int c1;
            cout<<"Escolha o conjunto para ser impresso:"<<endl;
            cin>> c1;
            cout<<Conjuntos[c1-1];
        }
        else if(x==7)
            break;
        system("pause");
    }

    return 0;
}
