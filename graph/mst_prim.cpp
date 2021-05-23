#include "graph.h"
#include "adj_list.h"
#include "priority_queue.h"

using namespace std;

PriorityQueueItem *GetItem(PriorityQueue &queue, int id) {
    for (auto &it : queue.q) {
        PRIM_Vertex *v = static_cast<PRIM_Vertex *>(it.data);
        if (id == v->id) {
            return &it;
        }
    }
    return nullptr;
}

int GetWeight(const Graph& graph, int u, int v) {
    for (const auto &it : graph) {
        auto edge = dynamic_cast<const Undirected_Weighted_Edge *>(it);
        if (edge->u.id == u && edge->v.id == v) {
            return edge->weight;
        }
        if (edge->u.id == v && edge->v.id == u) {
            return edge->weight;
        }
    }
    return INT32_MAX;
}

void MST_PRIM(const Graph& graph, int start_id) {
    AdjList adj_list(graph);

    vector<PriorityQueueItem> src_data;
    for (const auto &it : adj_list.vertexs) {
        int key = INT32_MAX;
        if (it.first == start_id) {
            key = 0;
        }
        src_data.push_back({key, it.second});
    }

    PriorityQueue q{src_data};

    PriorityQueueItem min;
    while(q.extract_min(min)) {
        PRIM_Vertex *vertex_u = static_cast<PRIM_Vertex *>(min.data);
        int u = vertex_u->id;
        for (auto v : adj_list.relations[u]) {
            PRIM_Vertex *vertex_v = static_cast<PRIM_Vertex *>(adj_list.vertexs[v]);
            auto q_v = GetItem(q, v);
            int weight = GetWeight(graph, u, v);
            if (q_v != nullptr && weight < q_v->key) {
                vertex_v->pre_id = u;
                q.decrease_key(q_v, weight);
            }
        }
    }
}