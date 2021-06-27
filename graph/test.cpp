#include <iostream>
#include <algorithm>
#include "bfs.h"
#include "dfs.h"
#include "strong_connected_components.h"
#include "mst_kruskal.h"
#include "mst_prim.h"
#include "priority_queue.h"
#include "bellman_ford.h"

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

void test_MST_KRUSKAL() {
    Vertex a{'a'}, b{'b'}, c{'c'}, d{'d'}, e{'e'}, f{'f'}, g{'g'}, h{'h'}, i{'i'};
    Undirected_Weighted_Edge ab(a, b, 4);
    Undirected_Weighted_Edge ah(a, h, 8);
    Undirected_Weighted_Edge bc(b, c, 8);
    Undirected_Weighted_Edge bh(b, h, 11);
    Undirected_Weighted_Edge cd(c, d, 7);
    Undirected_Weighted_Edge cf(c, f, 4);
    Undirected_Weighted_Edge ci(c, i, 2);
    Undirected_Weighted_Edge de(d, e, 9);
    Undirected_Weighted_Edge df(d, f, 14);
    Undirected_Weighted_Edge ef(e, f, 10);
    Undirected_Weighted_Edge fg(f, g, 2);
    Undirected_Weighted_Edge gh(g, h, 1);
    Undirected_Weighted_Edge gi(g, i, 6);
    Undirected_Weighted_Edge hi(h, i, 7);
    Graph graph{&ab, &ah, &bc, &bh, &cd, &cf, &ci, &de, &df, &ef, &fg, &gh, &gi, &hi};
    
    set<pair<int, int>> A = MST_KRUSKAL(graph);

    cout << "MST result:" << endl;
    for (const auto& i : A) {
        cout << static_cast<char>(i.first) << "-" << static_cast<char>(i.second)<< endl;
    }
    cout << "----" << endl;
}

void test_MST_PRIM() {
    PRIM_Vertex a{'a'}, b{'b'}, c{'c'}, d{'d'}, e{'e'}, f{'f'}, g{'g'}, h{'h'}, i{'i'};
    Undirected_Weighted_Edge ab(a, b, 4);
    Undirected_Weighted_Edge ah(a, h, 8);
    Undirected_Weighted_Edge bc(b, c, 8);
    Undirected_Weighted_Edge bh(b, h, 11);
    Undirected_Weighted_Edge cd(c, d, 7);
    Undirected_Weighted_Edge cf(c, f, 4);
    Undirected_Weighted_Edge ci(c, i, 2);
    Undirected_Weighted_Edge de(d, e, 9);
    Undirected_Weighted_Edge df(d, f, 14);
    Undirected_Weighted_Edge ef(e, f, 10);
    Undirected_Weighted_Edge fg(f, g, 2);
    Undirected_Weighted_Edge gh(g, h, 1);
    Undirected_Weighted_Edge gi(g, i, 6);
    Undirected_Weighted_Edge hi(h, i, 7);
    Graph graph{&ab, &ah, &bc, &bh, &cd, &cf, &ci, &de, &df, &ef, &fg, &gh, &gi, &hi};

    MST_PRIM(graph, 'a');
    
    cout << graph << endl;
}

void test_Bellman_Ford() {
    BELLMAN_FORD_Vertex s{'s'}, t{'t'}, x{'x'}, y{'y'}, z{'z'};
    
    Directed_Weighted_Edge tx(t, x, 5);
    Directed_Weighted_Edge ty(t, y, 8);
    Directed_Weighted_Edge tz(t, z, -4);
    Directed_Weighted_Edge yx(y, x, -3);
    Directed_Weighted_Edge yz(y, z, 9);
    Directed_Weighted_Edge zx(z, x, 7);
    Directed_Weighted_Edge zs(z, s, 2);
    Directed_Weighted_Edge st(s, t, 6);
    Directed_Weighted_Edge sy(s, y, 7);
    Directed_Weighted_Edge xt(x, t, -2);
    
    Graph graph{&tx, &ty, &tz, &yx, &yz, &zx, &zs, &st, &sy, &xt};

    bool result = bellman_ford(graph, 's');

    cout << result << endl;
    cout << graph << endl;
}

int main() {
    test_BFS();
    test_DFS();
    test_strong_connected_components();
    test_MST_KRUSKAL();
    test_MST_PRIM();
    test_Bellman_Ford();
}