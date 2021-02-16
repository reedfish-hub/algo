#ifndef _ADJ_LIST_H_
#define _ADJ_LIST_H_

#include <vector>
#include <map>
#include <ostream>
#include "vertex.h"
#include "graph.h"

using Relation = std::vector<int>;

struct AdjList {
    std::vector<Vertex> vertexs;
    std::map<int, Relation> relations;

    AdjList(const Graph& g);
    Vertex *get_vertex(int index);
    Relation *get_relation(int index);
};

std::ostream & operator<<(std::ostream & os, const AdjList &adj_list);

#endif