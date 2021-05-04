#ifndef _DFS_H_
#define _DFS_H_
#include <ostream>
#include "adj_list.h"

using DFS_TREE = std::map<int, std::vector<int>>;

void DFS(AdjList &adj_list, DFS_TREE &result);
void DFS(AdjList_New &adj_list, DFS_TREE &result);

std::ostream & operator<<(std::ostream & os, const DFS_TREE &dfs_tree);

#endif