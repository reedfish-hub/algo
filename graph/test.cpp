#include <iostream>
#include <algorithm>
#include "bfs.h"
#include "dfs.h"
#include "strong_connected_components.h"

using namespace std;

void test_BFS() {
    BFS_Vertex r{'r'}, s{'s'}, v{'v'}, w{'w'}, t{'t'}, x{'x'}, u{'u'}, y{'y'};
    Undirected_Edge rs{r, s}, rv{r, v}, sw{s, w}, wt{w, t}, wx{w, x}, tx{t, x}, tu{t, u}, xu{x, u}, xy{x, y}, uy{u, y};
    Graph g{&rs, &rv, &sw, &wt, &wx, &tx, &tu, &xu, &xy, &uy};
    AdjList adj_list(g);
    
    BFS(adj_list, 's');
    
    cout << "BFS(start = s) result:" << endl;
    cout << adj_list;
    cout << "----" << endl;
}

void test_DFS() {
    DFS_Vertex u{'u'}, v{'v'}, w{'w'}, x{'x'}, y{'y'}, z{'z'};
    Directed_Edge uv{u, v}, ux{u, x}, vy{v, y}, wy{w, y}, wz{w, z}, xv{x, v}, yx{y, x}, zz{z, z};
    Graph g{&uv, &ux, &vy, &wy, &wz, &xv, &yx, &zz};
    AdjList adj_list(g);
    DFS_TREE result;

    DFS(adj_list, result);

    cout << "DFS result:" << endl;
    cout << adj_list << endl;
    cout << "DFS tree:" << endl;
    cout << result << endl;
    cout << "----" << endl;
}

void test_strong_connected_components() {
    DFS_Vertex a{'a'}, b{'b'}, c{'c'}, d{'d'}, e{'e'}, f{'f'}, g{'g'}, h{'h'};
    Directed_Edge ab{a, b}, bc{b, c}, be{b, e}, bf{b, f}, cd{c, d}, cg{c, g},
                  dc{d, c}, dh{d, h}, ea{e, a}, ef{e, f}, fg{f, g}, gf{g, f},
                  gh{g, h}, hh{h, h};
    Graph graph{&cg, &gf, &fg, &gh, &hh, &cd, &dh, &dc, &be, &ea, &ab, &bc, &bf, &ef};

    DFS_TREE result = strong_connected_components(graph);
    cout << "strong connected components:" << endl;
    cout << result << endl;
    cout << "----" << endl;
}

int main() {
    test_BFS();
    test_DFS();
    test_strong_connected_components();
}