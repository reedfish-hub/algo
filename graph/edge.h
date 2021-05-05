#ifndef _EDGE_H_
#define _EDGE_H_

#include <utility>
#include <ostream>
#include <string>
#include <vector>
#include "vertex.h"

class Edge {
private:
    virtual std::string connection_string() const {
        return ",";
    }
public:
    Vertex_New &u;
    Vertex_New &v;

    Edge(Vertex_New &e_u, Vertex_New &e_v) :
        u(e_u),
        v(e_v) {}

    // std::pair<from, to>
    virtual std::vector<std::pair<int, int>> relations() const = 0;
    
    friend std::ostream & operator<<(std::ostream & os, const Edge &e) {
        os << e.u << e.connection_string() << e.v;
        return os;
    }
};

class Undirected_Edge : public Edge {
public:
    Undirected_Edge(Vertex_New &e_u, Vertex_New &e_v) :
        Edge(e_u, e_v) {}
    
    std::string connection_string() const override{
        return "-";
    }

    std::vector<std::pair<int, int>> relations() const override {
        return {{u.id, v.id},
                {v.id, u.id}};
    }
};

class Directed_Edge : public Edge {
public:
    Directed_Edge(Vertex_New &e_u, Vertex_New &e_v) :
        Edge(e_u, e_v) {}
    
    std::string connection_string() const override{
        return "->";
    }

    std::vector<std::pair<int, int>> relations() const override {
        return {{u.id, v.id}};
    }
};

#endif