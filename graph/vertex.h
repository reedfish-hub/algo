#ifndef _VERTEX_H_
#define _VERTEX_H_
#include <ostream>
#include <vector>
#include <algorithm>
#include <string>

enum BFS_VERTEX_COLOR {
    WHITE,
    GRAY,
    BLACK,
};

// extern std::vector<int> g_order;

// struct Vertex {
//     int index;
//     BFS_VERTEX_COLOR color = WHITE;
//     int d = -1; //BFS DFS
//     int pre_index = -1; //BFS
//     int f = -1; //DFS

//     bool operator==(const Vertex& v) const {
//         return index == v.index;
//     }

//     bool operator<(const Vertex &v) const {
//         if (g_order.empty()) {
//             return index < v.index;
//         }
//         auto pos = find(g_order.begin(), g_order.end(), index);
//         auto pos_v = find(g_order.begin(), g_order.end(), v.index);
//         return pos < pos_v;
//     }

//     void set_BFS(BFS_VERTEX_COLOR color, int d, int pre_index) {
//         this->color = color;
//         this->d = d;
//         this->pre_index = pre_index;
//     }

//     void set_DFS(BFS_VERTEX_COLOR color, int d, int f) {
//         this->color = color;
//         this->d = d;
//         this->f = f;
//     }
// };

// std::ostream & operator<<(std::ostream & os, const Vertex &v);

////////

// 新Vertex
class Vertex_New {
private:
    virtual std::string additional_infomation() const {
        return "";
    }
public:
    int id;
    
    explicit Vertex_New(int v_id) : id(v_id) {}

    friend std::ostream & operator<<(std::ostream & os, const Vertex_New &v) {
        os << static_cast<char>(v.id) << v.additional_infomation();
        return os;
    }
};

// 用于BFS的Vertex
class BFS_Vertex : public Vertex_New {
public:
    explicit BFS_Vertex(int v_id, BFS_VERTEX_COLOR v_color = WHITE, int v_d = -1, int v_pre_index = -1) :
        Vertex_New(v_id),
        color(v_color),
        d(v_d),
        pre_index(v_pre_index) {}
    
    BFS_VERTEX_COLOR color;
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
class DFS_Vertex : public Vertex_New {
public:
    explicit DFS_Vertex(int v_id, BFS_VERTEX_COLOR v_color = WHITE, int v_d = -1, int v_f = -1, int v_pre_id = -1) :
        Vertex_New(v_id),
        color(v_color),
        d(v_d),
        f(v_f),
        pre_id(v_pre_id) {}
    
    BFS_VERTEX_COLOR color;
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

#endif