#ifndef SEQ_H
#define SEQ_H
#include <vector>
#include<iostream>

class Seq
{
        std::vector<unsigned long int> V;
    protected:
        void set (unsigned long int);
        unsigned long int get (unsigned long int);
        void clear ();
        virtual void gen_elems(int i)=0;

    public:
        Seq();
        virtual ~Seq();
        virtual unsigned long int elem(int i);
        virtual void print(std::ostream& os);
        virtual int length();
        virtual void imprimi(int i=-1,int j=-1);

        friend std::ostream& operator <<(std::ostream&,Seq&);

};



#endif // SEQ_H
