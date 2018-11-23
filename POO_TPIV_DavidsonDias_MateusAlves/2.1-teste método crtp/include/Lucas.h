#ifndef LUCAS_H
#define LUCAS_H
#include <Seq.h>

class Lucas:public Seq
{
        std::vector<unsigned long int>* returSeq();
        static std::vector<unsigned long int> *Vet;
    public:
        Lucas(int i=0);
        virtual ~Lucas();
        void gen_elems(int i);


};

#endif // LUCAS_H
