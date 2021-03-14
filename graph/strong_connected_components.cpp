#include <algorithm>
#include <iostream>
#include "adj_list.h"
#include "dfs.h"

using namespace std;

void trans_to_T(const Graph &g, Graph &g_T) {
    g_T = g;
    for (auto &i : g_T) {
        swap(i.first, i.second);
    }
}

void sort_T(const vector<Vertex> &vertexs, Graph &g_T) {
    vector<pair<int, int>> f_index;
    for (const auto &i: vertexs) {
        f_index.push_back({i.f, i.index});
    }
    sort(f_index.rbegin(), f_index.rend());
    
    g_order = {};
    for (const auto &i: f_index) {
        g_order.push_back(i.second);
    }

    sort(g_T.begin(), g_T.end());
}

void strong_connected_components(Graph &g) {
    AdjList adj_list(g);
    DFS_TREE result;
    DFS(adj_list, result);

    Graph g_T;
    trans_to_T(g, g_T);

    sort_T(adj_list.vertexs, g_T);
    
    AdjList adj_list_T(g_T);
    DFS_TREE result_T;
    DFS(adj_list_T, result_T);
    
    cout << "strong connected components:" << endl;
    cout << result_T;
}