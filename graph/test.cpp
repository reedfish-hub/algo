#include <iostream>
#include "bfs.h"
#include "dfs.h"

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
        Edge{{'u'}, {'v'}},
        Edge{{'u'}, {'x'}},
        Edge{{'v'}, {'y'}},
        Edge{{'w'}, {'y'}},
        Edge{{'w'}, {'z'}},
        Edge{{'x'}, {'v'}},
        Edge{{'y'}, {'x'}},
        Edge{{'z'}, {'z'}},
        };
    cout << "Graph:" << endl;
    cout << g;

    AdjList adj_list{g};
    cout << "AdjList:" << endl;
    cout << adj_list;

    DFS(adj_list);
    cout << "After DFS:" << endl;
    cout << adj_list;
}

int main() {
    test_BFS();
    cout << "---" << endl;
    test_DFS();
}