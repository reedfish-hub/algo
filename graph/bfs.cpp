#include <deque>
#include "adj_list.h"

using namespace std;

void BFS(AdjList &adj_list, int s) {
    Vertex *p_s = adj_list.get_vertex(s);
    p_s->set(GRAY, 0, -1);

    deque<int> q;
    q.push_back(s);
    
    while (q.size() != 0) {
        int u = q[0];
        q.pop_front();
        
        Vertex *p_u = adj_list.get_vertex(u);
        Relation *p_u_relation = adj_list.get_relation(u);

        for (auto v: *p_u_relation) {
            Vertex *p_v = adj_list.get_vertex(v);
            if (p_v->color == WHITE) {
                p_v->set(GRAY, p_u->d + 1, p_u->index);
                q.push_back(v);
            }
        }
        p_u->color = BLACK;
    }
}