#ifndef _MST_KRUSKAL_H_
#define _MST_KRUSKAL_H_

#include <set>
#include <utility>
#include "graph.h"

std::set<std::pair<int, int>> MST_KRUSKAL(const Graph& graph);

#endif