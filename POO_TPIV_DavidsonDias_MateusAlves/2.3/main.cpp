#include <iostream>
#include <map>
#include <string>
#include <fstream>

using namespace std;

struct dado
{
    int phone;
    string address;
};
struct dado2
{
    string name;
    string address;
};
ostream& operator << (ostream& op, const dado2& h)
{
    op<<h.name<<"\n";
    op<<h.address;
    return op;
}
ostream& operator << (ostream& op, const dado& h)
{
    op<<h.address<<"\n";
    op<<h.phone;
    return op;
}

int main()
{
    multimap<string, struct dado> m;
    map<int, struct dado2> m2;
    string nome, line;
    int x;

    cout<<"Nome e extensao do arquivo: ";
    cin>>nome;
    ifstream in(nome.c_str());

    cout<<"Qual versao de pesquisa:\n1- Por nome;\n2- Por telefone."<<endl;
    cin>>x;


    if(x==1)
    {
        string key;
        while(getline(in, line))
        {
            struct dado d;
            key=line;
            getline(in, line);
            d.address=line;
            in>>d.phone;
            getline(in,line);
            m.insert(pair<string, struct dado>(key,d));
        }
        cout<<"Nome do assinante: ";
        fflush(stdin);
        getline (cin, key);

        pair<multimap<string, struct dado>::iterator, multimap<string, struct dado>::iterator> ppp;
        ppp = m.equal_range(key); /// Retorna os limites de um intervalo que inclui todos os elementos do recipiente em que têm um equivalente para key.

        cout << endl << "Dados de "<<key<<":" << endl;
        for (multimap<string, struct dado>::iterator it2 = ppp.first; it2 != ppp.second; ++it2)
        {
            cout <<">> "<< (*it2).second << endl<<endl;
        }
    }
    else if(x==2)
    {
        int key;
        while(getline(in, line))
        {
            struct dado2 d;
            d.name=line;
            getline(in, line);
            d.address=line;
            in>>key;
            getline(in,line);
            m2[key]=d;
        }
        cout<<"Numero do assinante: ";
        cin>>key;

        cout<<m2[key]<<endl;
    }
    return 0;
}
