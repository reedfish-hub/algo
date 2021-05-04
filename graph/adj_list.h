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

////

class AdjList_New {
public:
    AdjList_New(const Graph_New& g);

    std::map<int, Vertex_New *>vertexs;
    std::map<int, Relation> relations;

    friend std::ostream & operator<<(std::ostream & os, const AdjList_New &adj_list) {
        os << "vertexs:" << std::endl;
        for (const auto &it : adj_list.vertexs) {
            os << *(it.second) << std::endl;
        }
        os << std::endl;

        os << "relations:" << std::endl;
        for (const auto &it : adj_list.relations) {
            os << static_cast<char>(it.first) << ":";
            for (const auto & id: it.second) {
                os << static_cast<char>(id) << ",";
            }
            os << std::endl;
        }
        return os;
    }
};

#endif