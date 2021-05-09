#include <set>
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include "graph.h"
#include "adj_list.h"

using namespace std;

auto find_set(vector<set<int>> &v_sets, int u) {
    for (auto it = v_sets.begin(); it != v_sets.end(); it++) {
        if (it->count(u) != 0) {
            return it;
        }
    }
    return v_sets.end();
}

void merge(set<int> &u_set, const set<int> &v_set) {
    for (const auto &v : v_set) {
        u_set.insert(v);
    }
}

set<pair<int, int>> MST_KRUSKAL(const Graph& graph) {
    AdjList adj_list(graph);
    vector<set<int>> vertexs;
    for (const auto &it : adj_list.vertexs) {
        vertexs.push_back({it.first});
    }

    vector<pair<int, pair<int, int>>> weight_vertexs;
    for (const auto &it : graph) {
        auto edge = dynamic_cast<const Undirected_Weighted_Edge*>(it);
        weight_vertexs.push_back({edge->weight, {edge->u.id, edge->v.id}});
    }
    sort(begin(weight_vertexs), end(weight_vertexs));

    set<pair<int, int>> A;
    
    for (const auto &it : weight_vertexs) {
        int u = it.second.first;
        int v = it.second.second;
        auto u_set = find_set(vertexs, u);
        auto v_set = find_set(vertexs, v);
        if (u_set != v_set) {
            A.insert({u, v});
            merge(*u_set, *v_set);
            vertexs.erase(v_set);
        }
    }
    return A;
}