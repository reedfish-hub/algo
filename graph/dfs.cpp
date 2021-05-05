#include "dfs.h"

using namespace std;

int g_time;

ostream & operator<<(ostream & os, const DFS_TREE &dfs_tree) {
    for (const auto& it: dfs_tree) {
        os << static_cast<char>(it.first) << "->";
        for (const auto &id: it.second) {
            os << static_cast<char>(id) << "->";
        }
        os << endl;
    }
    return os;
}

// 计算root_id以及id是否为此树上的最后一个元素
int get_root_id(const DFS_TREE &result, int id, bool &at_last) {
    at_last = false;
    for (const auto it : result) {
        const vector<int> &tree = it.second;
        // 如果id就是树根
        if (id == it.first) {
            // 如果tree只有根节点，则id为最后一个元素
            at_last = tree.empty();
            return it.first;
        }
        // 如果id不是树根，且在树上找到了id
        if (find(begin(tree), end(tree), id) != end(tree)) {
            at_last = (id == tree.back());
            return it.first;
        }
    }
    return -1;
}

void add_to_result(DFS_TREE &result, const DFS_Vertex &u) {
    bool at_last = false;
    int root_id = get_root_id(result, u.pre_id, at_last);

    // 如果pre_id在结果中还没有，或者不是最后一个元素，则新创建一个树根
    if (root_id == -1 || !at_last) {
        result[u.id] = vector<int> {};
    } else {
        result[root_id].push_back(u.id);
    }
}

void DFS_VISIT(AdjList &adj_list, DFS_Vertex &u, DFS_TREE &result) {
    
    add_to_result(result, u);
    
    g_time++;
    u.d = g_time;
    u.color = GRAY;
    const Relation &u_relation = adj_list.relations[u.id];
    for (const auto &v: u_relation) {
        DFS_Vertex *p_v = dynamic_cast<DFS_Vertex *>(adj_list.vertexs[v]);
        if (p_v->color == WHITE) {
            p_v->pre_id = u.id;
            DFS_VISIT(adj_list, *p_v, result);
        }
    }
    u.color = BLACK;
    g_time++;
    u.f = g_time;
}

void DFS(AdjList &adj_list, DFS_TREE &result, const std::vector<int> &order) {
    g_time = 0;
    // 不指定顺序
    if (order.size() == 0) {
        for (const auto &it: adj_list.vertexs) {
            DFS_Vertex *p_u = dynamic_cast<DFS_Vertex *>(it.second);
            if (p_u->color == WHITE) {
                DFS_VISIT(adj_list, *p_u, result);
            }
        }
    } else {
        // 指定顺序
        for (const auto &u: order) {
            DFS_Vertex *p_u = dynamic_cast<DFS_Vertex *>(adj_list.vertexs[u]);
            if (p_u->color == WHITE) {
                DFS_VISIT(adj_list, *p_u, result);
            }
        }
    }
}
