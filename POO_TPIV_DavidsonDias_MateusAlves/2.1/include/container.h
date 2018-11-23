#ifndef CONTAINER_H
#define CONTAINER_H
#include <Seq.h>

class container
{
        std::vector<Seq*> S;
    public:
        container();
        virtual ~container();
        void set(Seq*);
        friend std::ostream& operator << (std::ostream& op, const container& h);
};

#endif // CONTAINER_H
