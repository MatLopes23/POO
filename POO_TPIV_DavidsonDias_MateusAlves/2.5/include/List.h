#ifndef LIST_H
#define LIST_H
#include <string>

namespace DataStructures{
class List
{
    struct Link{
        int dado;
        Link *prox;
        Link(int d,Link *p);
        ~Link();
    };
    struct Link *Lista;

    public:

        List();
        List(const List& h);
        List& operator = (const List& );
        List operator + (const List& ) const;
        List& operator += (const List& );
        List& operator +=(const int d);
        List& operator -= (const int d);
        int operator () (const int )const;
        int size()const;
        bool procura(const int d)const;
        virtual ~List();
        void LeDeArquivo(const std::string& nomeArquivo);
        void GravarArquivo(const std::string& nomeArquivo);

        friend std::ostream& operator << (std::ostream& op, const List& h);
        friend std::istream& operator >> (std::istream& op, List&);

};
}


#endif // LIST_H
