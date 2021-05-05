#include <deque>
#include "adj_list.h"

using namespace std;

void BFS(AdjList &adj_list, int s) {
    BFS_Vertex *p_s = dynamic_cast<BFS_Vertex *>(adj_list.vertexs[s]);
    p_s->color = GRAY;
    p_s->d = 0;
    p_s->pre_index = -1;

    deque<int> q;
    q.push_back(s);
    
    while (q.size() != 0) {
        int u = q[0];
        q.pop_front();
        
        BFS_Vertex *p_u = dynamic_cast<BFS_Vertex *>(adj_list.vertexs[u]);
        const Relation& u_relation = adj_list.relations[u];

        for (const auto &v: u_relation) {
            BFS_Vertex *p_v = dynamic_cast<BFS_Vertex *>(adj_list.vertexs[v]);
            if (p_v->color == WHITE) {
                p_v->color = GRAY;
                p_v->d = p_u->d + 1;
                p_v->pre_index = p_u->id;
                q.push_back(v);
            }
        }
        p_u->color = BLACK;
    }
}