#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<string> v;
    string nome;
    cout<<"Insira nome do arquivo: ";
    cin>>nome;
    ifstream arq(nome.c_str());
    string line;
    while((arq>>line))/// O while vai ser executado enquanto hover dados para serem lidas (palavra por palavra)
        v.push_back(line);/// armazenando no vector

    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;

    sort(v.begin(),v.end());

    cout<<endl;
    for(int i = 0; i < v.size(); i++)
        cout << v[i] << endl;
}
