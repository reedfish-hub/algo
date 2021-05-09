#ifndef _ADJ_LIST_H_
#define _ADJ_LIST_H_

#include <vector>
#include <map>
#include <ostream>
#include "vertex.h"
#include "graph.h"

using Relation = std::vector<int>;

class AdjList {
public:
    AdjList(const Graph& graph);

    std::map<int, Vertex *>vertexs;
    std::map<int, Relation> relations;
};

std::ostream & operator<<(std::ostream & os, const AdjList &adj_list);

#endif