#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <vector>
#include <ostream>
#include "edge.h"

using Graph = std::vector<Edge>;

std::ostream & operator<<(std::ostream & os, const Graph &g);

/////
//class Graph_New {
//protected:
//    const std::vector<const Edge_New &> edges;
//};

using Graph_New = std::vector<const Edge_New *>;
std::ostream & operator<<(std::ostream & os, const Graph_New &g);

#endif