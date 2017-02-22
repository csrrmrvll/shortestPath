#include <iterator>
#include <set>
#include <utility>
#include "ShortestPath.h"

using namespace std;

ShortestPath::ShortestPath(Graph && g)
:   g{g}
{
}

DijkstraScores ShortestPath::compute()
{
    DijkstraScores ds;
    Heap h;
    using Visited = set<Vertex>;
    Visited vd;
    const DijkstraScore infinity = 1000000;
    for (auto it : this->g)
    {
        Vertex v = it.first;
        h.insert(v == 1 ? 0 : infinity,v);
        ds.insert(make_pair(v,v == 1 ? 0 : infinity));
    }
    while (h.nonEmpty())
    {
        const Heap::value_type top = h.pop();
        const DijkstraScore dscurrent = top.first;
        const Vertex current = top.second;
        vd.insert(current);
        const Edges edges = this->g[current];
        for (auto e : edges)
        {
            const Vertex v = e.first;
            if (vd.count(v) == 0)
            {
                h.erase(v);
                const Distance d = e.second;
                const DijkstraScore tv = dscurrent + d,
                                    dsv = ds[v],
                                    ns = min(dsv,tv);
                ds[v] = ns;
                h.insert(ns,v);
            }
        }
    }
    return ds;
}
