#ifndef PENTAGONAL_H
#define PENTAGONAL_H
#include <Seq.h>

class Pentagonal:public Seq
{

    public:
        Pentagonal(int i=0);
        virtual ~Pentagonal();
        void gen_elems(int i);


};

#endif // PENTAGONAL_H
