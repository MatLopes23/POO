#ifndef PELL_H
#define PELL_H
#include <Seq.h>

class Pell:public Seq
{

    public:
        Pell(int i=0);
        virtual ~Pell();
        void gen_elems(int i);


};

#endif // PELL_H
