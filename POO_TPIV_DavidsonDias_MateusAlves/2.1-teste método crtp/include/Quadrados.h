#ifndef QUADRADOS_H
#define QUADRADOS_H
#include <Seq.h>

class Quadrados:public Seq
{

    public:
        Quadrados(int i=0);
        virtual ~Quadrados();
        void gen_elems(int i);


};

#endif // QUADRADOS_H
