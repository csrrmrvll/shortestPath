#include <utility>
#include "Heap.h"

using namespace std;

void Heap::push(DijkstraScore ds, Vertex v)
{
    this->c.emplace(make_pair(ds,v));
}

Vertex Heap::pop()
{
    return this->erase(begin(this->c));
}

Vertex Heap::erase(Container::const_iterator it)
{
    const Vertex v = it->second;
    this->c.erase(it);
    return v;
}

void Heap::erase(DijkstraScore ds)
{
    this->c.erase(ds);
}

bool Heap::processed(DijkstraScore ds) const
{
    return this->c.count(ds) == 0;
}
