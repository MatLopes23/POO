#ifndef TRIANGULAR_H
#define TRIANGULAR_H
#include <Seq.h>

class Triangular:public Seq
{

    public:
        Triangular(int i=0);
        virtual ~Triangular();
        void gen_elems(int i);


};

#endif // TRIANGULAR_H
