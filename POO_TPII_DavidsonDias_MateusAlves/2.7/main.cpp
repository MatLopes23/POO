#include <iostream>
#include <Lista_encadeada.h>
#include<stdlib.h>

using namespace std;

int main()
{
    Lista_encadeada LIST;


    while(1)
    {
        system("cls");
         cout<<"----LISTA ENCADEADA----"<<endl;

        int x,y,z;
        cout<<"1-Inserir elemento.\n"
              "2-Remover elemento.\n"
              "3-Procurar elemento.\n"
              "4-Gravar lista em disco.\n"
              "5-Ler elementos de arquivo.\n"
              "6-Sair.\n";
        cin>>x;
        if(x==1)
        {
            cout<<"Elemento: ";
            cin>>y;
            LIST.inserir(y);
            cout<<"Lista:\n";
            LIST.imprimir();


        }
        else if(x==2)
        {
            cout<<"Elemento: ";
            cin>>y;
            LIST.remover(y);
            cout<<"Lista:\n";
            LIST.imprimir();

        }
        else if(x==3)
        {
            cout<<"Elemento: ";
            cin>>y;
            z=LIST.procura(y);
            if(z<0)
                cout<<"Valor "<<y<<" nao existente.\n";
            else
                cout<<"Valor "<<y<<" encontrado na posicao "<<z<<".\n";

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
            cout<<"Lista:\n";
            LIST.imprimir();
        }
        else if(x==6)
        {
            break;
        }

    system("pause");
    }


    return 0;
}
