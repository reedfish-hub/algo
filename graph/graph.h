#ifndef _GRAPH_H_
#define _GRAPH_H_
#include <vector>
#include <ostream>
#include "edge.h"

using Graph = std::vector<Edge>;

std::ostream & operator<<(std::ostream & os, const Graph &g);

#endif