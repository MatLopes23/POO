#ifndef LUCAS_H
#define LUCAS_H
#include <Seq.h>

class Lucas:public Seq
{

    public:
        Lucas(int i=0);
        virtual ~Lucas();
        void gen_elems(int i);


};

#endif // LUCAS_H
