#include <algorithm>
#include <iostream>
#include "adj_list.h"
#include "dfs.h"
#include <vector>

using namespace std;

vector<int> get_order(const map<int, Vertex *> &vertexs) {
    vector<pair<int, int>> f_id;
    for (const auto &it: vertexs) {
        DFS_Vertex *p_v = dynamic_cast<DFS_Vertex *>(it.second);
        f_id.push_back({p_v->f, p_v->id});
    }
    
    sort(f_id.rbegin(), f_id.rend());
    
    vector<int> result;
    for (const auto &it: f_id) {
        result.push_back(it.second);
    }
    
    return result;
}

void clear_vertexs(const map<int, Vertex *> &vertexs) {
    for (const auto &it: vertexs) {
        DFS_Vertex *p_v = dynamic_cast<DFS_Vertex *>(it.second);
        *p_v = DFS_Vertex{p_v->id};
    }
}

vector<Directed_Edge> get_edge_T(const Graph &graph) {
    vector<Directed_Edge> result;
    for (const auto &it : graph) {
        result.push_back(Directed_Edge{it->v, it->u}); //交换顺序
    }
    return result;
}

DFS_TREE strong_connected_components(Graph &g) {
    AdjList adj_list(g);
    DFS_TREE result;
    DFS(adj_list, result);

    vector<int> order = get_order(adj_list.vertexs);
    
    clear_vertexs(adj_list.vertexs);

    vector<Directed_Edge> edge_T = get_edge_T(g);
    Graph g_T;
    for (const auto &it : edge_T) {
        g_T.push_back(&it);
    }
    
    AdjList adj_list_T(g_T);
    DFS_TREE result_T;
    DFS(adj_list_T, result_T, order);
    
    return result_T;
}