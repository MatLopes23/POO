#ifndef C_H
#define C_H
#include<B.h>
#include<A.h>


class C : public A
{
    B obj;
    public:
        virtual ~C();

};

#endif // C_H
