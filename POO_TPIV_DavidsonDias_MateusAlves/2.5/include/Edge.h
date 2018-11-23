#ifndef EDGE_H
#define EDGE_H

class Edge
{
    private:
        int x,y;

    public:
        Edge(const int a=0,const int b=0);
        int get_inicio()const;
        int get_fim()const;
        void set(const int a,const int b);
        virtual ~Edge() {};
};

inline int Edge::get_inicio()const
{
    return x;
};
inline int Edge::get_fim()const
{
    return y;
};
inline Edge::Edge(const int a,const int b)
{
    if(a<=0||b<=0)
        x=y=0;
    else
    {
        x=a;
        y=b;
    }
};
inline void Edge::set(const int a,const int b)
{
    if(a<=0||b<=0)
        x=y=0;
    else
    {
        x=a;
        y=b;
    }
};

#endif // EDGE_H
