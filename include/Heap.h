#ifndef HEAP_H
#define HEAP_H

#include <map>

using DijkstraScore = int;
using Vertex = int;
using Container = std::multimap<DijkstraScore,Vertex>;
using NodeIterator = Container::const_iterator;

class Heap
{
public:
    using value_type = Container::value_type;
    void insert(value_type && v);
    void insert(DijkstraScore ds, Vertex v);
    value_type pop();
    bool nonEmpty();
    void erase(Vertex v);

private:
    value_type erase(NodeIterator it);

    Container c;
};

#endif // HEAP_H
