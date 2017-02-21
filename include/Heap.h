#ifndef HEAP_H
#define HEAP_H

#include <map>

using DijkstraScore = int;
using Vertex = int;

class Heap
{
public:
    void push(DijkstraScore ds, Vertex v);
    Vertex pop();

private:
    using Container = std::multimap<DijkstraScore,Vertex>;

    Vertex erase(Container::const_iterator it);
    void erase(DijkstraScore ds);
    bool processed(DijkstraScore ds) const;

    static const DijkstraScore default_ds = 1000000;
    Container c;
};

#endif // HEAP_H
