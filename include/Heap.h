#ifndef HEAP_H
#define HEAP_H

#include <map>

using DijkstraScore = int;
using Vertex = int;
using Container = std::multimap<DijkstraScore,Vertex>;
using NodeIterator = Container::const_iterator;
using Pair = std::pair<bool,NodeIterator>;

class Heap
{
public:
    using value_type = Container::value_type;
    void insert(value_type && v);
    void insert(DijkstraScore ds, Vertex v);
    value_type pop();
    bool nonEmpty();
    Pair contains(DijkstraScore ds) const;

private:
    value_type erase(NodeIterator it);
    void erase(DijkstraScore ds);

    Container c;
};

#endif // HEAP_H
