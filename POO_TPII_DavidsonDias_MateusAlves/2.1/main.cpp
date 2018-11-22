#include <iostream>
#include<string>

using namespace std;
void rot13(string nome_arq);
void decorot13(string nome_arq);

int main()
{
    int x;
    string nome;

    cout << "Insira nome do arquivo: " << endl;
    cin>>nome;

    cout<<"Escolha a opcao desejada:\n1-codificar\n2-decodificar " <<endl;
    cin>>x;
    if(x==1)
        rot13(nome);
    else if(x==2)
        decorot13(nome);


    return 0;
}
