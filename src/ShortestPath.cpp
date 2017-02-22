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
    using NotVisited = set<Vertex>;
    NotVisited nv;
    const DijkstraScore infinity = 1000000;
    for (auto it : this->g)
    {
        Vertex v = it.first;
        h.insert(v == 1 ? 0 : infinity,v);
        ds.insert(make_pair(v,v == 1 ? 0 : infinity));
        nv.insert(v);
    }
    while (h.nonEmpty())
    {
        const Heap::value_type current = h.pop();
        const DijkstraScore dscurrent = ds[current.first];
        const Edges edges = this->g[current.second];
        for (auto e : edges)
        {
            const Vertex v = e.first;
            if (nv.count(v) != 0)
            {
                h.erase(v);
                const Distance d = e.second;
                const DijkstraScore dsv = min(ds[v],dscurrent + d);
                ds[v] = dsv;
                h.insert(dsv,v);
            }
        }
    }
    return ds;
}
