#ifndef _PRIORITY_QUEUE_H_
#define _PRIORITY_QUEUE_H_

#include <vector>

struct PriorityQueueItem {
    int key;
    void *data;
};

class PriorityQueue {
public:
    PriorityQueue(const std::vector<PriorityQueueItem> &src_data);
    void insert(const PriorityQueueItem& item);
    PriorityQueueItem minimum();
    bool extract_min(PriorityQueueItem &min_item);
    void decrease_key(int oldKey, int newKey);
private:
    std::vector<PriorityQueueItem> q;
    void build_min_heap();
    void min_heapify(int i);
    void exchange(int i, int j);
};

#endif