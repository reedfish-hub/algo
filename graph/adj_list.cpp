#include "adj_list.h"
#include "graph.h"

using namespace std;

AdjList::AdjList(const Graph& graph) {
    for (const auto &edge : graph) {
        // 更新this->vertexs
        vertexs[edge->u.id] = &(edge->u);
        vertexs[edge->v.id] = &(edge->v);
        
        // 更新this->relations
        for (auto r : edge->relations()) {
            int from = r.first;
            int to = r.second;
            if (this->relations.count(from) == 0) {
                this->relations[from] = std::vector<int> {to};
            } else {
                this->relations[from].push_back(to);
            }
        }
    }
}

std::ostream & operator<<(std::ostream & os, const AdjList &adj_list) {
    os << "vertexs:" << std::endl;
    for (const auto &it : adj_list.vertexs) {
        os << *(it.second) << std::endl;
    }
    os << std::endl;

    os << "relations:" << std::endl;
    for (const auto &it : adj_list.relations) {
        os << static_cast<char>(it.first) << ":";
        for (const auto & id: it.second) {
            os << static_cast<char>(id) << ",";
        }
        os << std::endl;
    }
    return os;
}