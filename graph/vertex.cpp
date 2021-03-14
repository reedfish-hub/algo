#include <string>
#include "vertex.h"

using namespace std;

ostream & operator<<(ostream & os, const Vertex &v) {
    os << static_cast<char>(v.index) << "(";
    
    string color_str = "";
    if (v.color == WHITE) {
        color_str = "WHITE";
    } else if (v.color == GRAY) {
        color_str = "GRAY";
    } else if (v.color == BLACK) {
        color_str = "BLACK";
    }
    os << color_str << ",";
    
    if (v.d == -1) {
        os << "INF";
    } else {
        os << v.d;
    }
    os << ",";
    
    if (v.pre_index == -1) {
        os << "NIL";
    } else {
        os << static_cast<char>(v.pre_index);
    }
    
    os << ",";
    if (v.f == -1) {
        os << "INF";
    } else {
        os << v.f;
    }
    
    os << ")";
    return os;
}

vector<int> g_order;