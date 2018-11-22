#include <iostream>
#include<string>
#include<fstream>
#include<vector>

using namespace std;

void rot13(string nome_arq)
{

    ifstream arq(nome_arq.c_str());
    ///As duas linhas seguintes sao responsaveis para alterar a extensao do arquivo, mantendo apenas o nome original,sobrescrevendo a extensao
    nome_arq.erase(nome_arq.rfind('.'));
    nome_arq.append(".crp");
    ofstream out(nome_arq);

    string s;
    while(getline(arq, s)){

        for(int i=0;i<s.size();i++)
        {
            /** Utilizando a tabela ASCII verificamos se o caractere esta na primeira ou segunda metade do alfabeto,
                para imcrementar ou decrementer '13', obedecendo as especificacoes do rot13 */
            if((s[i]>=97 && s[i]<=109)|| (s[i]>=65 && s[i]<=77))
                s[i]+=13;
            else if((s[i]>=110 && s[i]<=122)|| (s[i]>=78 && s[i]<=90))
                s[i]-=13;
        }
       out << s << "\n";
  }
   cout<< "arquivo codificado: " << nome_arq<<endl;

}


void decorot13(string nome_arq)
{

    ifstream arq(nome_arq.c_str());
    ///As duas linhas seguintes sao responsaveis para alterar a extensao do arquivo, mantendo apenas o nome original,sobrescrevendo a extensao
    nome_arq.erase(nome_arq.find('.'));
    nome_arq.append(".tzd");
    ofstream out(nome_arq);

    string s;
    while(getline(arq, s)){

        for(int i=0;i<s.size();i++)
        {
            /** Utilizando a tabela ASCII verificamos se o caractere esta na primeira ou segunda metade do alfabeto,
                para imcrementar ou decrementer '13', obedecendo as especificacoes do rot13 */
            if((s[i]>=97 && s[i]<=109)|| (s[i]>=65 && s[i]<=77))
                s[i]+=13;
            else if((s[i]>=110 && s[i]<=122)|| (s[i]>=78 && s[i]<=90))
                s[i]-=13;
        }

       out << s << "\n";
  }
  cout<< "arquivo decodificado: " << nome_arq<<endl;

}
