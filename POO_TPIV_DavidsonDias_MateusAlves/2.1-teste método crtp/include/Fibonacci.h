#ifndef FIBONACCI_H
#define FIBONACCI_H
#include <Seq.h>

class Fibonacci:public Seq
{
        std::vector<unsigned long int>* returSeq();
        static std::vector<unsigned long int> *Vet;
    public:
        Fibonacci(int i=0);
        virtual ~Fibonacci();
        void gen_elems(int i);


};


#endif // FIBONACCI_H
