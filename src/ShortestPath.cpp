#include <iterator>
#include <utility>
#include "ShortestPath.h"

using namespace std;

ShortestPath::ShortestPath(Graph && g)
:   g{g}
{
}

DijkstraScores ShortestPath::compute()
{
    Heap h;
    for (auto it : this->g)
    {
        Vertex v = it.first;
        h.insert(this->ds[v],v);
    }
    const Heap::value_type s = move(h.pop());
    while (h.nonEmpty())
    {
        using Edges = pair<NodeIterator,NodeIterator>;
        const Edges edges = this->g.equal_range(s.second);
        const DijkstraScore dss = s.first;
        Heap h2;
        DijkstraScore dsv = default_ds;
        for (auto it = edges.first; it != edges.second; ++it)
        {
            const Vertex v = it->second;
            const Pair p = h.contains(dsv);
            if (p.first)
            {
                dsv = dss + dsv;
                h2.insert(dsv,v);
            }
        }
        Heap::value_type v = h2.pop();
        this->ds[v.second] = v.first;
        h.insert(move(v));
    }
    return this->ds;
}
