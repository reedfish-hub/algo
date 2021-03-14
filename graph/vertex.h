#ifndef _VERTEX_H_
#define _VERTEX_H_
#include <ostream>
#include <vector>
#include <algorithm>

enum BFS_VERTEX_COLOR {
    WHITE,
    GRAY,
    BLACK,
};

extern std::vector<int> g_order;

struct Vertex {
    int index;
    BFS_VERTEX_COLOR color = WHITE;
    int d = -1; //BFS DFS
    int pre_index = -1; //BFS
    int f = -1; //DFS

    bool operator==(const Vertex& v) const {
        return index == v.index;
    }

    bool operator<(const Vertex &v) const {
        if (g_order.empty()) {
            return index < v.index;
        }
        auto pos = find(g_order.begin(), g_order.end(), index);
        auto pos_v = find(g_order.begin(), g_order.end(), v.index);
        return pos < pos_v;
    }

    void set_BFS(BFS_VERTEX_COLOR color, int d, int pre_index) {
        this->color = color;
        this->d = d;
        this->pre_index = pre_index;
    }

    void set_DFS(BFS_VERTEX_COLOR color, int d, int f) {
        this->color = color;
        this->d = d;
        this->f = f;
    }
};

std::ostream & operator<<(std::ostream & os, const Vertex &v);

#endif