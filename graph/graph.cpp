#include "graph.h"
#include <iostream>

using namespace std;

ostream & operator<<(ostream & os, const Graph &g) {
    for (const auto& e: g) {
        os << (*e) << endl;
    }
    return os;
}