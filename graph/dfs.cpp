
#include "adj_list.h"
#include "dfs.h"

#include <iostream>

using namespace std;

int g_time;

void DFS_VISIT(AdjList &adj_list, Vertex &u, DFS_TREE &result, int root_index) {
    g_time++;
    u.d = g_time;
    u.color = GRAY;
    Relation *p_u_relation = adj_list.get_relation(u.index);
    for (auto v: *p_u_relation) {
        Vertex *p_v = adj_list.get_vertex(v);
        if (p_v->color == WHITE) {
            result[root_index].push_back(p_v->index);
            p_v->pre_index = u.index;
            DFS_VISIT(adj_list, *p_v, result, root_index);
        }
    }
    u.color = BLACK;
    g_time++;
    u.f = g_time;
}

void DFS(AdjList &adj_list, DFS_TREE &result) {
    g_time = 0;
    for (auto &u: adj_list.vertexs) {
        if (u.color == WHITE) {
            result[u.index] = vector<int>{};
            DFS_VISIT(adj_list, u, result, u.index);
        }
    }
}

ostream & operator<<(ostream & os, const DFS_TREE &dfs_tree) {
    for (const auto& i: dfs_tree) {
        os << static_cast<char>(i.first) << "->";
        for (const auto &j: i.second) {
            os << static_cast<char>(j) << "->";
        }
        os << endl;
    }
    return os;
}


void DFS_VISIT(AdjList_New &adj_list, DFS_Vertex &u, DFS_TREE &result, int root_index) {
    g_time++;
    u.d = g_time;
    u.color = GRAY;
    const Relation &u_relation = adj_list.relations[u.id];
    for (const auto &v: u_relation) {
        DFS_Vertex *p_v = dynamic_cast<DFS_Vertex *>(adj_list.vertexs[v]);
        if (p_v->color == WHITE) {
            result[root_index].push_back(p_v->id);
            p_v->pre_id = u.id;
            DFS_VISIT(adj_list, *p_v, result, root_index);
        }
    }
    u.color = BLACK;
    g_time++;
    u.f = g_time;
}

void DFS(AdjList_New &adj_list, DFS_TREE &result) {
    g_time = 0;
    for (const auto &it: adj_list.vertexs) {
        DFS_Vertex *p_u = dynamic_cast<DFS_Vertex *>(it.second);
        if (p_u->color == WHITE) {
            result[p_u->id] = vector<int>{};
            DFS_VISIT(adj_list, *p_u, result, p_u->id);
        }
    }
}