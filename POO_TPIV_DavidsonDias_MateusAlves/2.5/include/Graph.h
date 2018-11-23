#ifndef GRAPH_H
#define GRAPH_H
#include<List.h>
#include<vector>
#include<Edge.h>

class Graph
{
    private:
        int V,A;
        std::vector<DataStructures::List> Grafo;

        void DFS(int *v, int s)const;

    public:
        Graph(const int n=0);
        virtual ~Graph();
        bool insert(const Edge&);
        bool remove(const Edge&);
        bool edge(const Edge&)const;
        int get_vertices()const;
        int get_arestas()const;
        int coonnectedComponents()const;

        friend std::ostream& operator << (std::ostream& op, const Graph& h);

};

inline int Graph::get_vertices()const{return V;};
inline int Graph::get_arestas()const{return A;};

#endif // GRAPH_H
