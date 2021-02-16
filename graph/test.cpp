#include <iostream>
#include "bfs.h"

using namespace std;

int main() {
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