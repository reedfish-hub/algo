#include "edge.h"

using namespace std;

ostream & operator<<(ostream & os, const Edge &e) {
    os << e.first << "->" << e.second << endl;
    return os;
}