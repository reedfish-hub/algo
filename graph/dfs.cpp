
#include "adj_list.h"

int g_time;

void DFS_VISIT(AdjList &adj_list, Vertex &u) {
    g_time++;
    u.d = g_time;
    u.color = GRAY;
    Relation *p_u_relation = adj_list.get_relation(u.index);
    for (auto v: *p_u_relation) {
        Vertex *p_v = adj_list.get_vertex(v);
        if (p_v->color == WHITE) {
            p_v->pre_index = u.index;
            DFS_VISIT(adj_list, *p_v);
        }
    }
    u.color = BLACK;
    g_time++;
    u.f = g_time;
}

void DFS(AdjList &adj_list) {
    g_time = 0;
    for (auto &u: adj_list.vertexs) {
        if (u.color == WHITE) {
            DFS_VISIT(adj_list, u);
        }
    }
}