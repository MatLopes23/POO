#include <iostream>
#include<InterSet.h>
#include<vector>
#include<stdlib.h>

using namespace std;

int main ()
{
    vector <InterSet> Conjuntos;
    int num, x;

    cout<<"Digite a quantidade de conjuntos com elementos entre 0 e 100: ";
    cin>>num;

    cout<<"\nDeseja ler conjuntos de arquivos:\n1-Sim\n2-Nao"<<endl;
    cin>>x;
    if(x==1)
        for(int i=1;i<=num;i++)
        {
            string nomeArquivo;
            InterSet obj;
            Conjuntos.push_back(obj);
            cout<<"Nome do arquivo: "<<endl;
            cin>>nomeArquivo;
            Conjuntos[i-1].LeDeArquivo(nomeArquivo);
        }
    else if(x==2)
    {
        cout<<"\nObs: Para encerrar a insercao de elementos no conjunto digite um numero negativo"<<endl;

        for(int i=1;i<=num;i++)
        {
            InterSet obj;
            Conjuntos.push_back(obj);
            cout<<"Elementos do conjunto "<<i<<" : "<<endl;
            while(1)
            {
                int aux;
                cin>>aux;
                if(aux<0)
                    break;
                if(!Conjuntos[i-1].InsereElemento(aux))
                    cout<<"Valor "<<aux<<" nao inserido."<<endl;
            }

        }
    }

    while(1)
    {
        system("cls");
        cout<<"Escolha a operacao a ser realizada nos conjuntos:\n"
                "1-Remover elemento de um conjunto.\n"
                "2-Uniao de dois conjuntos.\n"
                "3-Intersecao de dois conjuntos.\n"
                "4-Verificar se dois conjuntos sao iguais.\n"
                "5-Imprimir Conjunto.\n"
                "6-Sair.\n"
                "--------------------------------------------------------\n";
        cin>>x;

        if(x==1)
        {
            cout<<"Escolha o Conjunto e o elemento a ser removido (separado por espaco):\n";
            int conj, elemento;
            cin>> conj;
            cin>> elemento;
            if(!Conjuntos[conj-1].RemoveElemento(elemento))
                cout<<"O elemento nao existe neste conjunto"<<endl;
        }
        else if(x==2)
        {
            cout<<"Escolha os dois Conjuntos para fazer a uniao (separado por espaco):"<<endl;
            int c1, c2;
            InterSet novo;
            cin>> c1;
            cin>> c2;
            novo.Uniao(Conjuntos[c1-1], Conjuntos[c2-1]);
            Conjuntos.push_back(novo);
            cout<<"O conjunto "<< Conjuntos.size() <<" contem a Uniao de "<< c1 << " e " << c2 << "."<<endl;
        }
        else if(x==3)
        {
            cout<<"Escolha os dois Conjuntos para fazer a intersecao (separado por espaco):"<<endl;
            int c1, c2;
            InterSet novo;
            cin>> c1;
            cin>> c2;
            novo.Intersecao(Conjuntos[c1-1], Conjuntos[c2-1]);
            Conjuntos.push_back(novo);
                cout<<"O conjunto "<< Conjuntos.size() <<" contem a Intersecao de "<< c1 << " e " << c2 << "."<<endl;
        }
        else if(x==4)
        {
            int c1, c2;
            cout<<"Escolha os dois Conjuntos para verificar se soa iguais (separado por espaco):"<<endl;
            cin>> c1;
            cin>> c2;
            if(Conjuntos[c1-1].Igual(Conjuntos[c2-1]))
                cout<<"Conjuntos iguais"<<endl;
            else
                cout<<"Conjuntos diferentes"<<endl;
        }
        else if(x==5)
        {
            int c1;
            cout<<"Escolha o conjunto para ser impresso:"<<endl;
            cin>> c1;
            Conjuntos[c1-1].Imprime();
        }
        else if(x==6)
            break;
    system("pause");
    }

     return 0;
}
