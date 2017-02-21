#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include <map>
#include "Heap.h"

using Graph = std::map<Vertex,Vertex>;
using ShortestPaths = std::map<Vertex,DijkstraScore>;

class ShortestPath
{
public:
    ShortestPath(Graph && g);
    ShortestPaths compute();

private:
    Graph g;
    Heap h;
    ShortestPaths sp;
};

#endif // SHORTESTPATH_H
