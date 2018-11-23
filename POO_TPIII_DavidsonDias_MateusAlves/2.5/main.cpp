#include <iostream>
#include<CWindow.h>
#include<CWindowSingleton.h>
#include<stdlib.h>

void teste2_CWindow(CWindow& h);
void teste_CWindow(CWindow h);
void teste2_CWindowSingleton(CWindowSingleton& h);
void teste_CWindowSingleton(CWindowSingleton h);

using namespace std;

int main()
{
    CWindow *janela;
    int op;

    cout<<"---------------CWindow----------------"<<endl<<endl;

    cout<<"Inserir caracteristicas da janela:\n1-Manualmente\n2-Ler de arquivo\n";
    cin>>op;
    if(op==1)
    {
        int op2;
        cout<<"Criar janela por valores default:\n1-sim\n2-nao"<<endl;
        cin>>op2;

        if(op2==1)
            janela=new CWindow;

        else if(op2==2)
        {
            janela=new CWindow;
            cin>>*janela;
        }
    }

    else if(op==2)
    {
        std::string nome;

        cout<<"Nome do arquivo: ";
        cin>>nome;
        janela=new CWindow;
        janela->LeDeArquivo(nome);

    }

    while(1)
    {
        int op2;
        system("cls");
        janela->show();
        cout<<"Operacoes:\n"
            "1-Redirecionar janela;\n"
            "2-Alterar caracteristicas da janela;\n"
            "3-Visualizar caracteristicas da janela;\n"
            "4-Gravar janela em arquivo;\n"
            "5-Sair.\n"<<endl;
        cin>>op;

        if(op==1)
        {
            int x,y;
            cout<<"----------------------------------------"<<endl;
            cout<<"1-Alterar posicao.\n2-Alterar dimensao.\n";
            cin>>op2;

            if(op2==1)
            {
                cout<<"Nova posicao: ";
                cin>>x;
                cin>>y;
                janela->move(x,y);
            }
            else if(op2==2)
            {
                cout<<"Nova dimensao: ";
                cin>>x;
                cin>>y;
                janela->resize(x,y);
            }
        }
        else if(op==2)
        {
            string aux;
            cout<<"----------------------------------------"<<endl;
            cout<<"1-Alterar tamanho da fonte.\n"
                "2-Alterar tipo de fonte.\n"
                "3-Alterar cor da fonte.\n"
                "4-Alterar cor da pena.\n"
                "5-Alterar cor do pincel.\n";
            cin>>op2;
            if(op2==1)
            {
                int tam;
                cout<<"Novo tamanho da fonte: ";
                cin>>tam;
                janela->Cset_tamanho(tam);

            }
            else if(op2==2)
            {
                cout<<"Novo tipo de fonte: ";
                cin>>aux;
                janela->Cset_tipo_fonte(aux);
            }
            else if(op2==3)
            {
                cout<<"Nova cor da fonte: ";
                cin>>aux;
                janela->Cset_fonte(aux);
            }
            else if(op2==4)
            {
                cout<<"Nova cor da pena: ";
                cin>>aux;
                janela->Cset_pena(aux);
            }
            else if(op2==5)
            {
                cout<<"Nova cor do pincel: ";
                cin>>aux;
                janela->Cset_pincel(aux);
            }
        }
        else if(op==3)
        {
            cout<<"----------------------------------------"<<endl;
            cout<<*janela;
        }
        else if(op==4)
        {
            string nome;
            cout<<"Nome do arquivo a ser gravado a janela: ";
            cin>>nome;

            janela->GravarArquivo(nome);
        }
        else if(op==5)
            break;

        system("pause");
    }


    int x;
    cout<<"Para testar as funçoes na classe digite 1:";
    cin>>x;
    if(x=1)
    {
        {
            ///Teste Singleton

            CWindowSingleton *janelaSg=CWindowSingleton::Instace();
            ///CWindowSingleton obj1, obj2;         Erro de Compilação
            ///obj1=*janela                         Erro de Compilação
            cout<<"\nTeste das funcoes CWindowSingleton\n";
            cout<<"\nAntes das funcoes\n"<<*janelaSg;
            ///teste_CWindowSingleton(*janelaSg);   Erro de Compilação

            teste2_CWindowSingleton(*janelaSg);
            cout<<"\nDepois da funcao por referencia\n"<<*janelaSg;
        }
        {
            ///Teste CWindow
            cout<<"\nTeste das funcoes CWindow\n";

            CWindow janela2;
            cout<<"\nAntes das funcoes\n"<<janela2;
            teste_CWindow(janela2);
            cout<<"\nDepois da funcao por copia\n"<<janela2;
            teste2_CWindow(janela2);
            cout<<"\nDepois da funcao por referencia\n"<<janela2;
        }

    }
    return 0;
}
