#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <map>
#include <utility>
#include "Heap.h"

using Graph = std::map<Vertex,Vertex>;
using DijkstraScores = std::map<Vertex,DijkstraScore>;

class ShortestPath
{
public:
    ShortestPath(Graph && g);
    DijkstraScores compute();

private:
    static const DijkstraScore default_ds = 1000000;
    Graph g;
    DijkstraScores ds;
};

#endif // SHORTESTPATH_H
