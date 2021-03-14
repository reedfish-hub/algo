#include <iostream>
#include <algorithm>
#include "bfs.h"
#include "dfs.h"
#include "strong_connected_components.h"

using namespace std;

void test_BFS() {
    Graph g {
        BI_Edge('r', 's'),
        BI_Edge('r', 'v'),
        BI_Edge('s', 'w'),
        BI_Edge('w', 't'),
        BI_Edge('w', 'x'),
        BI_Edge('t', 'x'),
        BI_Edge('t', 'u'),
        BI_Edge('x', 'u'),
        BI_Edge('x', 'y'),
        BI_Edge('u', 'y'),
        };
    cout << "Graph:" << endl;
    cout << g;

    AdjList adj_list{g};
    cout << "AdjList:" << endl;
    cout << adj_list;

    BFS(adj_list, 's');
    cout << "After BFS:" << endl;
    cout << adj_list;
}

void test_DFS() {
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
    cout << "Graph:" << endl;
    cout << g;

    g_order = {'c', 'g', 'f', 'h', 'd', 'b', 'a', 'e'};
    sort(g.begin(), g.end());
    cout << "After sort, Graph:" << endl;
    cout << g;

    AdjList adj_list{g};
    cout << "AdjList:" << endl;
    cout << adj_list;

    DFS_TREE result;
    DFS(adj_list, result);
    cout << "After DFS:" << endl;
    cout << adj_list;
    cout << "DFS tree:" << endl;
    cout << result;
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
    //test_BFS();
    //cout << "---" << endl;
    //test_DFS();
    //cout << "---" << endl;
    test_strong_connected_components();
}