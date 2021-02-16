#ifndef _VERTEX_H_
#define _VERTEX_H_
#include <ostream>

enum BFS_VERTEX_COLOR {
    WHITE,
    GRAY,
    BLACK,
};

struct Vertex {
    int index;
    BFS_VERTEX_COLOR color = WHITE;
    int d = -1; //BFS DFS
    int pre_index = -1; //BFS
    int f = -1; //DFS

    bool operator==(const Vertex& v) {
        return index == v.index;
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