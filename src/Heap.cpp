#include <utility>
#include "Heap.h"

using namespace std;

void Heap::insert(Heap::value_type && v)
{
    this->c.emplace(move(v));
}

void Heap::insert(DijkstraScore ds, Vertex v)
{
    this->insert(make_pair(ds,v));
}

Heap::value_type Heap::pop()
{
    return this->erase(begin(this->c));
}

bool Heap::nonEmpty()
{
    return this->c.empty() == false;
}

Heap::value_type Heap::erase(NodeIterator it)
{
    const value_type v = *it;
    this->c.erase(it);
    return v;
}

void Heap::erase(DijkstraScore ds)
{
    this->c.erase(ds);
}

Pair Heap::contains(DijkstraScore ds) const
{
    const NodeIterator it = this->c.find(ds);
    bool found = it != end(this->c);
    return make_pair(found, it);
}
