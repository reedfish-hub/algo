
#include "adj_list.h"
#include "dfs.h"

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