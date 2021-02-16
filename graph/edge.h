#ifndef _EDGE_H_
#define _EDGE_H_

#include <utility>
#include <ostream>
#include "vertex.h"

using Edge = std::pair<Vertex, Vertex>;

#define BI_Edge(u, v) Edge{{u}, {v}}, Edge{{v}, {u}}

std::ostream & operator<<(std::ostream & os, const Edge &e);

#endif