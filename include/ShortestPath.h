#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <map>
#include <utility>
#include <vector>
#include "Heap.h"

using Distance = int;
using Edge = std::pair<Vertex,Distance>;
using Edges = std::vector<Edge>;
using Graph = std::map<Vertex,Edges>;
using DijkstraScores = std::map<Vertex,DijkstraScore>;

class ShortestPath
{
public:
    ShortestPath(Graph && g);
    DijkstraScores compute();

private:
    Graph g;
};

#endif // SHORTESTPATH_H
