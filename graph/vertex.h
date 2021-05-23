#ifndef _VERTEX_H_
#define _VERTEX_H_
#include <ostream>
#include <vector>
#include <algorithm>
#include <string>

enum VERTEX_COLOR {
    WHITE,
    GRAY,
    BLACK,
};

class Vertex {
private:
    virtual std::string additional_infomation() const {
        return "";
    }
public:
    int id;
    
    explicit Vertex(int v_id) : id(v_id) {}

    friend std::ostream & operator<<(std::ostream & os, const Vertex &v) {
        os << static_cast<char>(v.id) << v.additional_infomation();
        return os;
    }
};

// 用于BFS的Vertex
class BFS_Vertex : public Vertex {
public:
    explicit BFS_Vertex(int v_id, VERTEX_COLOR v_color = WHITE, int v_d = -1, int v_pre_index = -1) :
        Vertex(v_id),
        color(v_color),
        d(v_d),
        pre_index(v_pre_index) {}
    
    VERTEX_COLOR color;
    int d;
    int pre_index;

    std::string additional_infomation() const override {
        std::string info = "(";

        std::string color_str = "";
        if (color == WHITE) {
            color_str = "WHITE";
        } else if (color == GRAY) {
            color_str = "GRAY";
        } else if (color == BLACK) {
            color_str = "BLACK";
        }

        info += color_str;
        info += ",d:";
        if (d == -1) {
            info += "INF";
        } else {
            info += std::to_string(d);
        }

        info += ",pre:";
        if (pre_index == -1) {
            info += "NIL";
        } else {
            info += static_cast<char>(pre_index);
        }
        
        info += ")";
        return info;
    }
};

// 用于DFS的Vertex
class DFS_Vertex : public Vertex {
public:
    explicit DFS_Vertex(int v_id, VERTEX_COLOR v_color = WHITE, int v_d = -1, int v_f = -1, int v_pre_id = -1) :
        Vertex(v_id),
        color(v_color),
        d(v_d),
        f(v_f),
        pre_id(v_pre_id) {}
    
    VERTEX_COLOR color;
    int d;
    int f;
    int pre_id;

    std::string additional_infomation() const override {
        std::string info = "(";

        std::string color_str = "";
        if (color == WHITE) {
            color_str = "WHITE";
        } else if (color == GRAY) {
            color_str = "GRAY";
        } else if (color == BLACK) {
            color_str = "BLACK";
        }
        info += color_str;
        
        info += ",d:";
        if (d == -1) {
            info += "INF";
        } else {
            info += std::to_string(d);
        }

        info += ",f:";
        if (f == -1) {
            info += "INF";
        } else {
            info += std::to_string(f);
        }

        info += ",pre:";
        if (pre_id == -1) {
            info += "NIL";
        } else {
            info += static_cast<char>(pre_id);
        }
        
        info += ")";
        return info;
    }
};

// 用于PRIM算法的Vertex
class PRIM_Vertex : public Vertex {
public:
    explicit PRIM_Vertex(int v_id, int v_pre_id = -1) :
        Vertex(v_id),
        pre_id(v_pre_id) {}
    
    int pre_id;

    std::string additional_infomation() const override {
        std::string info = "(";

        info += "pre:";
        if (pre_id == -1) {
            info += "NIL";
        } else {
            info += static_cast<char>(pre_id);
        }
        
        info += ")";
        return info;
    }
};

#endif