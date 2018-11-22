#include <iostream>
#include<CWindowSingleton.h>
#include<stdlib.h>

using namespace std;

int main()
{

    CWindowSingleton *janela=CWindowSingleton::Instace();///Atribui o ponteiro que e retornado pela função 'CWindowSingleton::Instace()'
    CWindowSingleton djanela;///Atribui o ponteiro que e retornado pela função 'CWindowSingleton::Instace()'

    int op;

    cout<<"---------------CWindowSingleton----------------"<<endl<<endl;

    while(1)
    {
        int op2;
        system("cls");
        janela->show();
        cout<<"Operacoes:\n"
            "1-Redirecionar janela;\n"
            "2-Alterar caracteristicas da janela;\n"
            "3-Visualizar caracteristicas da janela;\n"
            "4-Alterar dados da janela com dados de um arquivo.\n"
            "5-Gravar janela em arquivo;\n"
            "6-Sair.\n"<<endl;
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
            janela->show();
            cout<<"Fonte:\n"
                "\tTamanho: "<<janela->Cget_tamanho()<<".\n"
                "\tTipo: "<<janela->Cget_tipo_fonte()<<".\n"
                "\tCor: "<<janela->Cget_fonte()<<".\n"
                "Pena: "<<janela->Cget_pena()<<".\n"
                "Pincel: "<<janela->Cget_pincel()<<".\n";
        }
        else if(op==4)
        {
            cout<<"----------------------------------------"<<endl;
            std::string nome;

            cout<<"Nome do arquivo: ";
            cin>>nome;
            janela->LeDeArquivo(nome);

        }
        else if(op==5)
        {
            cout<<"----------------------------------------"<<endl;
            string nome;
            cout<<"Nome do arquivo a ser gravado a janela: ";
            cin>>nome;

            janela->GravarArquivo(nome);
        }
        else if(op==6)
            break;

        system("pause");
    }



    return 0;
}

