#include "bellman_ford.h"
#include "adj_list.h"

void RELAX(int u, int v, int w, AdjList &adj_list)
{
    BELLMAN_FORD_Vertex *v_v = static_cast<BELLMAN_FORD_Vertex *>(adj_list.vertexs[v]);
    BELLMAN_FORD_Vertex *v_u = static_cast<BELLMAN_FORD_Vertex *>(adj_list.vertexs[u]);
    if (v_v->d > v_u->d + w) {
        v_v->d = std::min(10000, v_u->d + w);
        v_v->pre_id = v_u->id;
    }
}

bool VALID(int u, int v, int w, AdjList &adj_list)
{
    BELLMAN_FORD_Vertex *v_v = static_cast<BELLMAN_FORD_Vertex *>(adj_list.vertexs[v]);
    BELLMAN_FORD_Vertex *v_u = static_cast<BELLMAN_FORD_Vertex *>(adj_list.vertexs[u]);
    return (v_v->d <= v_u->d + w);
}

bool bellman_ford(Graph &graph, int s)
{
    AdjList adj_list(graph);
    BELLMAN_FORD_Vertex *v_s = static_cast<BELLMAN_FORD_Vertex *>(adj_list.vertexs[s]);
    v_s->d = 0;

    size_t v_num = adj_list.vertexs.size();
    for (int i = 0; i < v_num - 1; i ++) {
        for (auto e : graph) {
            const Directed_Weighted_Edge *edge = static_cast<const Directed_Weighted_Edge *>(e);
            RELAX(edge->u.id, edge->v.id, edge->weight, adj_list);
        }
    }

    for (auto e : graph) {
        const Directed_Weighted_Edge *edge = static_cast<const Directed_Weighted_Edge *>(e);
        if (!VALID(edge->u.id, edge->v.id, edge->weight, adj_list)) {
            return false;
        }
    }

    return true;
}