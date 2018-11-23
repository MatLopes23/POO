#include <iostream>
#include <Lista_encadeada.h>
#include<stdlib.h>

using namespace std;
using namespace DataStructures;
int main()
{
    Lista_encadeada LIST, LIST2, LIST3;


    while(1)
    {
        system("cls");
         cout<<"----LISTA ENCADEADA----"<<endl;

        int x,y,z;
        cout<<"1-Inserir elemento.\n"
              "2-Remover elemento.\n"
              "3-Procurar elemento em uma posicao.\n"
              "4-Gravar lista em disco.\n"
              "5-Ler elementos de arquivo.\n"
              "6-Concatenar Listas.\n"
              "7-Acrescentar segunda Lista na Primeira Lista (+=).\n"
              "8-Sair.\n";
        cin>>x;
        if(x==1)
        {
            cout<<"Elemento: ";
            cin>>LIST;
            cout<<"Lista:\n"<<LIST;
        }
        else if(x==2)
        {
            cout<<"Elemento: ";
            cin>>y;
            LIST-=y;
            cout<<"Lista:\n"<<LIST;
        }
        else if(x==3)
        {
            cout<<"Posicao: ";
            cin>>y;
            if(y>LIST.size()||y<0)
            {
                z=LIST(y);
                cout<<"Valor "<<z<<" encontrado na posicao "<<y<<".\n";
            }
            else
                cout<<"Posicao "<<y<<" nao existente.\n";



        }
        else if(x==4)
        {
            string s;
            cout<<"Nome do arquivo com extensao: ";
            cin>>s;
            LIST.GravarArquivo(s);
        }
        else if(x==5)
        {
            string s;
            cout<<"Nome do arquivo com extensao: ";
            cin>>s;
            LIST.LeDeArquivo(s);
            cout<<"Lista:\n"<<LIST;
        }
        else if(x==6)
        {
            int y;
            cout<<"Forneca o tamanho da  nova Lista para ser concatenada: ";
            cin>>y;
            cout<<"Elementos da nova Lista:\n";
            for(int i=0;i<y;i++)
                cin>>LIST2;
            LIST3=LIST+LIST2;
            cout<<"Lista Concatenada:\n"<<LIST3;
        }
        else if(x==7)
        {
            int y;
            cout<<"Forneca o tamanho da  nova Lista para ser acrescentada: ";
            cin>>y;
            cout<<"Elementos da nova Lista:\n";
            for(int i=0;i<y;i++)
                cin>>LIST2;
            LIST+=LIST2;
            cout<<"Lista :\n"<<LIST;
        }
        else if(x==8)
        {
            break;
        }

    system("pause");
    }


    return 0;
}
