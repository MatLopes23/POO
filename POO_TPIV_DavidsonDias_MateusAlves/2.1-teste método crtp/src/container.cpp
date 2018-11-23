#include "container.h"

container::container()
{
    //ctor
}

container::~container()
{
    S.clear();
}

void container::set (Seq *x)
{
    S.push_back(x);
}

std::ostream& operator << (std::ostream& op, const container& h)
{
    for(int i=0; i<h.S.size(); i++)
        h.S[i]->print(op);

    return op;
}

