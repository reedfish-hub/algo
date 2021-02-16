#include <algorithm>
#include "adj_list.h"
#include "graph.h"

using namespace std;

ostream & operator<<(ostream & os, const Relation &relation) {
    for (const auto& i: relation) {
        os << static_cast<char>(i) << "->";
    }
    return os;
}

ostream & operator<<(ostream & os, const AdjList &adj_list) {
    for (const auto& vertex: adj_list.vertexs) {
        os << vertex << " ";
    }
    os << endl;
    for (auto it = adj_list.relations.begin(); it != adj_list.relations.end(); it++) {
        os << static_cast<char>(it->first) << "->" << it->second << endl;
    }
    return os;
}

static void add_to_vertexs(vector<Vertex> &vertexs, const Vertex& v) {
    if (find(begin(vertexs), end(vertexs), v) == vertexs.end()) {
        vertexs.push_back(v);
    }
}

static void add_to_relation(Relation &relation, int index) {
    if (find(begin(relation), end(relation), index) == relation.end()) {
        relation.push_back(index);
    }
}

static void add_to_relations(std::map<int, Relation> &relations, int index0, int index1) {
    auto search = relations.find(index0);
    if (search != relations.end()) {
        add_to_relation(search->second, index1);
    } else {
        relations[index0] = Relation{index1};
    }
}

AdjList::AdjList(const Graph& g) {
    for (auto& e: g) {
        add_to_vertexs(vertexs, e.first);
        add_to_vertexs(vertexs, e.second);
        add_to_relations(relations, e.first.index, e.second.index);
    }
}

Vertex *AdjList::get_vertex(int index) {
    for (auto &i: vertexs) {
        if (i.index == index) {
            return &i;
        }
    }
    return nullptr;
}

Relation *AdjList::get_relation(int index) {
    auto search = relations.find(index);
    if (search != relations.end()) {
        return &search->second;
    }
    return nullptr;
}