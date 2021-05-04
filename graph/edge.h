#ifndef _EDGE_H_
#define _EDGE_H_

#include <utility>
#include <ostream>
#include <string>
#include <vector>
#include "vertex.h"

using Edge = std::pair<Vertex, Vertex>;

#define BI_Edge(u, v) Edge{{u}, {v}}, Edge{{v}, {u}}

std::ostream & operator<<(std::ostream & os, const Edge &e);

//////

class Edge_New {
private:
    virtual std::string connection_string() const {
        return ",";
    }
public:
    Vertex_New &u;
    Vertex_New &v;

    Edge_New(Vertex_New &e_u, Vertex_New &e_v) :
        u(e_u),
        v(e_v) {}

    // std::pair<from, to>
    virtual std::vector<std::pair<int, int>> relations() const = 0;
    
    friend std::ostream & operator<<(std::ostream & os, const Edge_New &e) {
        os << e.u << e.connection_string() << e.v;
        return os;
    }
};

class Undirected_Edge : public Edge_New {
public:
    Undirected_Edge(Vertex_New &e_u, Vertex_New &e_v) :
        Edge_New(e_u, e_v) {}
    
    std::string connection_string() const override{
        return "-";
    }

    std::vector<std::pair<int, int>> relations() const override {
        return {{u.id, v.id},
                {v.id, u.id}};
    }
};

class Directed_Edge : public Edge_New {
public:
    Directed_Edge(Vertex_New &e_u, Vertex_New &e_v) :
        Edge_New(e_u, e_v) {}
    
    std::string connection_string() const override{
        return "->";
    }

    std::vector<std::pair<int, int>> relations() const override {
        return {{u.id, v.id}};
    }
};

#endif