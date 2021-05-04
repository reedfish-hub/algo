#include <iostream>
#include <algorithm>
#include "bfs.h"
#include "dfs.h"
#include "strong_connected_components.h"

using namespace std;

void test_BFS() {
    BFS_Vertex r{'r'}, s{'s'}, v{'v'}, w{'w'}, t{'t'}, x{'x'}, u{'u'}, y{'y'};
    Undirected_Edge rs{r, s}, rv{r, v}, sw{s, w}, wt{w, t}, wx{w, x}, tx{t, x}, tu{t, u}, xu{x, u}, xy{x, y}, uy{u, y};
    Graph_New g{&rs, &rv, &sw, &wt, &wx, &tx, &tu, &xu, &xy, &uy};
    AdjList_New adj_list(g);
    
    BFS(adj_list, 's');
    
    cout << "BFS(start = s) result:" << endl;
    cout << adj_list;
    cout << "----" << endl;
}

void test_DFS() {
    DFS_Vertex u{'u'}, v{'v'}, w{'w'}, x{'x'}, y{'y'}, z{'z'};
    Directed_Edge uv{u, v}, ux{u, x}, vy{v, y}, wy{w, y}, wz{w, z}, xv{x, v}, yx{y, x}, zz{z, z};
    Graph_New g{&uv, &ux, &vy, &wy, &wz, &xv, &yx, &zz};
    AdjList_New adj_list(g);
    DFS_TREE result;

    DFS(adj_list, result);

    cout << "DFS result:" << endl;
    cout << adj_list << endl;
    cout << "DFS tree:" << endl;
    cout << result << endl;
    cout << "----" << endl;
}

void test_strong_connected_components() {
    Graph g {
        Edge{{'a'}, {'b'}},
        Edge{{'b'}, {'c'}},
        Edge{{'b'}, {'e'}},
        Edge{{'b'}, {'f'}},
        Edge{{'c'}, {'d'}},
        Edge{{'c'}, {'g'}},
        Edge{{'d'}, {'c'}},
        Edge{{'d'}, {'h'}},
        Edge{{'e'}, {'a'}},
        Edge{{'e'}, {'f'}},
        Edge{{'f'}, {'g'}},
        Edge{{'g'}, {'f'}},
        Edge{{'g'}, {'h'}},
        Edge{{'h'}, {'h'}},
        };
    
    strong_connected_components(g);
}

int main() {
    test_BFS();
    test_DFS();
}