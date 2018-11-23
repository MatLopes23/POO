#ifndef MATRIZ_H
#define MATRIZ_H
#include<string>
#include<vector>
#include<iostream>
#include<fstream>


namespace Matematica
{
template <class T>class Matriz;
template <class T>std::ostream& operator << (std::ostream& op, const Matriz<T>&);
template <class T>std::istream& operator >> (std::istream& op,  Matriz<T>&);
template <class T>T it_maior(T &a, T &b)
{
    if(a>b)
        return a;
    else
        return b;
}
template <class T>
class Matriz
{

    T **M;
    int linhas,colunas;
    void Alocar();/// metodo privado para alocação da Matriz dado o numero de linhas e colunas
    void Desalocar();/// metodo privado para desalocação da Matriz

public:

    Matriz(const Matriz<T>& h);
    Matriz(const int l=0,const int c=0);
    Matriz<T>& operator=(const Matriz<T>& );
    Matriz<T> operator+(const Matriz<T>& )const;
    Matriz<T> operator-(const Matriz<T>& )const;
    Matriz<T>& operator+=(const Matriz<T>& );
    Matriz<T>& operator-=(const Matriz<T>& );
    Matriz<T> operator*(const Matriz<T>& )const;
    Matriz<T>& operator*=(const Matriz<T>& );
    Matriz<T> operator*(const std::vector<T>& )const;
    Matriz<T>& operator*=(const std::vector<T>& );
    T& operator()(const int i,const int j)const;
    Matriz<T>& operator >> (const std::string& nomeArquivo);
    Matriz<T>& operator << (const std::string& nomeArquivo)const;

    template <class V>
    friend std::ostream& operator<< (std::ostream& op, const Matriz<V>&);
    template <class V>
    friend std::istream& operator>> (std::istream& op,  Matriz<V>&);

    int size_coluna() const;
    int size_linha() const;
    virtual ~Matriz();


    class iterator;
    friend class iterator;
    class iterator
    {
        Matriz<T>& s;
        int index_l, index_c;
    public:
        iterator(Matriz<T>& is) : s(is), index_l(0), index_c(0) {}
        iterator(Matriz<T>& is, bool): s(is), index_l(is.linhas), index_c(is.colunas)  {}
        T operator*() const
        {
            return s(index_l,index_c);
        }

        T operator++(int)
        {
            if(index_c>=s.colunas)
            {
                index_l++;
                index_c=0;
                if(index_l>=s.linhas)
                    index_l=0;
                return s(index_l,index_c);
            }
            return s(index_l,index_c++);
        }
        iterator operator=(const iterator& rv)
        {
            if (this==&rv)
                return *this;
            s=rv.s;
            index_c = rv.index_c;
            index_l = rv.index_l;
            return *this;
        }
        bool operator==(const iterator& rv) const
        {
            return (index_c == rv.index_c)&&(index_l == rv.index_l);
        }
        bool operator!=(const iterator& rv) const
        {
            return (index_c != rv.index_c)||(index_l != rv.index_l);
        }
        bool operator>(const iterator& rv) const
        {
            return (*(*this)> *rv);
        }
    };
    iterator begin()
    {
        return iterator(*this);
    }
    iterator end()
    {
        return iterator(*this, true);
    }

};



template<class T>
void Matriz<T>::Desalocar()
{
    for(int i=0; i<linhas; i++)
        delete[] M[i];///Percorre toda as linhas da matriz para desalocando os vetores representando as colunas
    delete[] M;/// Desaloca o vetor de ponteiros que representa as linhas
}

template<class T>
void Matriz<T>::Alocar()
{
    M=new T*[linhas];/// alocação de um vetor de ponteiros de tamanho igual ao numero de linhas
    for(int i=0; i<linhas; i++)
        M[i]= new T[colunas];///alocando um vetor de doubles de tamanho igual ao numero de colunas

    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            M[i][j]=0;
}

template<class T>
Matriz<T>::Matriz(const Matriz<T>& h):linhas(h.linhas),colunas(h.colunas)
{
    Alocar();
    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            M[i][j]=h.M[i][j];
}

template<class T>
Matriz<T>::Matriz(const int l,const int c)
{
    linhas=l;
    colunas=c;
    if(l!=0 && c!=0)///condição para que haja a alocação da matriz somente quando o numero de linhas e colunas
        ///for determinado pelo usuario ou por algum metodo.
        Alocar();
    std::cout<<"Construtor pelas linhas e colunas"<<std::endl;

}

template<class T>
Matriz<T>& Matriz<T>::operator >> (const std::string& nomeArquivo)
{
    std::ifstream arq(nomeArquivo.c_str());
    T x;
    int y;
    /// x irá receber os tamanhos de linhas e colunas do inicio do arquivo
    arq>>y;
    linhas=y;
    arq>>y;
    colunas=y;
    Alocar();

    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            if(arq>>x)
                M[i][j]=x;

    return *this;
}

template<class T>
Matriz<T>::~Matriz()
{
    Desalocar();
    std::cout<<"Destrutor"<<std::endl;
}

template<class T>
Matriz<T>& Matriz<T>::operator << (const std::string& nomeArquivo)const
{
    std::ofstream out(nomeArquivo.c_str());

    out << linhas << " ";
    out << colunas << std::endl;
    for(int i=0; i<linhas; i++)
    {
        for(int j=0; j<colunas; j++)
            out << M[i][j] <<" ";
        out <<std::endl;
    }
}

template<class T>
Matriz<T> Matriz<T>::operator+(const Matriz<T>& h)const
{

    if(h.linhas==linhas && h.colunas==colunas)
    {
        Matriz<T> aux(linhas,colunas);

        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                aux.M[i][j]=h.M[i][j]+M[i][j];

        return aux;
    }
    else
    {
        Matriz<T> aux;
        return aux;
    }
}

template<class T>
Matriz<T> Matriz<T>::operator-(const Matriz<T>& h)const
{
    if(h.linhas==linhas && h.colunas==colunas)
    {
        Matriz<T> aux(linhas,colunas);

        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                aux.M[i][j]=M[i][j]-h.M[i][j];

        return aux;
    }
    else
    {
        Matriz<T> aux;
        return aux;
    }
}

template<class T>
Matriz<T>& Matriz<T>::operator+=(const Matriz<T>& h)
{
    if(h.linhas==linhas && h.colunas==colunas)
    {

        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                M[i][j]=h.M[i][j]+M[i][j];

        return *this;
    }


}

template<class T>
Matriz<T>& Matriz<T>::operator-=(const Matriz<T>& h)
{
    if(h.linhas==linhas && h.colunas==colunas)
    {
        for(int i=0; i<linhas; i++)
            for(int j=0; j<colunas; j++)
                M[i][j]=M[i][j]-h.M[i][j];

        return *this;
    }
    else
    {
        Matriz<T> aux;
        return aux;
    }

}

template<class T>
Matriz<T> Matriz<T>::operator*(const Matriz<T>& h)const
{
    if(colunas==h.linhas)
    {
        Matriz<T> aux(linhas,h.colunas);
        for(int i=0; i<linhas; i++)
            for(int j=0; j<h.colunas; j++)
                for(int k=0; k<colunas; k++)
                    aux.M[i][j]+=M[i][k]*h.M[k][j];

        return aux;
    }


}

template<class T>
Matriz<T>& Matriz<T>::operator*=(const Matriz<T>& h)
{

    if(colunas==h.linhas)
    {
        Matriz<T> aux(linhas,h.colunas);
        for(int i=0; i<linhas; i++)
            for(int j=0; j<h.colunas; j++)
                for(int k=0; k<colunas; k++)
                    aux.M[i][j]+=M[i][k]*h.M[k][j];

        *this =aux;
        return *this;
    }

}

template<class T>
Matriz<T> Matriz<T>::operator*(const std::vector<T>& vec)const
{
    if(colunas==vec.size())
    {
        Matriz<T> aux(linhas,1);

        for(int i=0; i<linhas; i++)
        {
            for(int j=0; j<vec.size(); j++)
                aux.M[i][0]+=(M[i][j]*vec[j]);
        }
        return aux;
    }
}

template<class T>
Matriz<T>& Matriz<T>::operator*=(const std::vector<T>& vec)
{
    if(linhas==vec.size())
    {
        Matriz<T> aux(linhas,1);

        for(int i=0; i<linhas; i++)
        {
            for(int j=0; j<vec.size(); j++)
                aux.M[i][0]+=(M[i][j]*vec[j]);
        }
        *this =aux;
        return *this;
    }

}

template<class T>
int Matriz<T>::size_coluna() const
{
    return colunas;
}

template<class T>
int Matriz<T>::size_linha() const
{
    return linhas;
}

template<class T>
Matriz<T>& Matriz<T>::operator=(const Matriz<T>& b)
{
    if (this==&b)
        return *this;

    Desalocar();
    linhas=b.linhas;
    colunas=b.colunas;

    Alocar();

    for(int i=0; i<linhas; i++)
        for(int j=0; j<colunas; j++)
            M[i][j]=b.M[i][j];

    return *this;
}

template<class T>
T& Matriz<T>::operator()(const int i,const int j)const
{
    if(i<linhas||j<colunas||i>0||j>0)
        return (M[i][j]);
}

template<class T>
std::ostream& operator << (std::ostream& op, const Matriz<T>& h)
{

    op<< h.linhas<<" "<< h.colunas <<std::endl;

    for(int i=0; i<h.linhas; i++)
    {
        for(int j=0; j<h.colunas; j++)
            op<<h.M[i][j]<<" ";
        op<<std::endl;
    }
    return op;
}

template<class T>
std::istream& operator >> (std::istream& op, Matriz<T>& h)
{
    h.Desalocar();

    op >> h.linhas;
    op >> h.colunas;
    h.Alocar();

    for(int i=0; i<h.linhas; i++)
        for(int j=0; j<h.colunas; j++)
            op>>h.M[i][j];

    return op;
}
}



#endif // MATRIZ_H
