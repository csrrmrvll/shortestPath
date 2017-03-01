#include <functional>
#include <iterator>
#include <set>
#include <utility>
#include "heap.h"
#include "ShortestPath.h"

using namespace std;
using namespace ads;

ShortestPath::ShortestPath(Graph && g)
:   g{g}
{
}

using DSVertex = pair<DijkstraScore,Vertex>;
auto comparator = [](const DSVertex & a, const DSVertex & b) { return a.first > b.first; };
DijkstraScores ShortestPath::compute()
{
    DijkstraScores ds;
    using MinDSHeap = heap<DSVertex,decltype(comparator)>;
    MinDSHeap h{comparator};
    using Visited = set<Vertex>;
    Visited vd;
    const DijkstraScore infinity = 1000000;
    for (auto it : this->g)
    {
        Vertex v = it.first;
        auto value = v == 1 ? 0 : infinity;
        h.push(make_pair(value,v));
        ds.insert(make_pair(v,value));
    }
    while (false == h.empty())
    {
        const DSVertex & top = h.pop();
        const DijkstraScore dscurrent = top.first;
        const Vertex current = top.second;
        ds[current] = dscurrent;
        vd.insert(current);
        const Edges edges = this->g[current];
        for (auto e : edges)
        {
            const Vertex v = e.first;
            if (vd.count(v) == 0)
            {
                const DijkstraScore dsv = ds[v];
                h.erase(make_pair(dsv,v));
                const Distance d = e.second;
                const DijkstraScore tv = dscurrent + d,
                                    ns = min(dsv,tv);
                ds[v] = ns;
                h.push(make_pair(ns,v));
            }
        }
    }
    return ds;
}
