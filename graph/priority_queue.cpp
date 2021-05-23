#include "priority_queue.h"
#include <iostream>
using namespace std;

inline int LEFT(int i) {
    return 2 * i + 1;
}

inline int RIGHT(int i) {
    return 2 * i + 2;
}

inline int PARENT(int i) {
    return (i - 1) / 2;
}

PriorityQueue::PriorityQueue(const vector<PriorityQueueItem> &src_data) {
    q = src_data;
    build_min_heap();
}

PriorityQueueItem PriorityQueue::minimum() {
    return q.front();
}

void PriorityQueue::min_heapify(int i) {
    int l = LEFT(i);
    int r = RIGHT(i);
    int smallest = i;
    if (l < q.size()) {
        if (q[l].key < q[i].key) {
            smallest = l;
        }
    }
    if (r < q.size()) {
        if (q[r].key < q[smallest].key) {
            smallest = r;
        }
    }
    if (smallest != i) {
        exchange(i, smallest);
        min_heapify(smallest);
    }
}

void PriorityQueue::build_min_heap() {
    for (int i = (q.size() / 2 - 1); i >= 0; i--) {
        min_heapify(i);
    }
}

bool PriorityQueue::extract_min(PriorityQueueItem &min_item) {
    if (q.size() < 1) {
        return false;
    }
    min_item = q.front();
    q.front() = q.back();
    q.erase(q.end() - 1);
    min_heapify(0);
    return true;
}

void PriorityQueue::exchange(int i, int j) {
    auto temp = q[i];
    q[i] = q[j];
    q[j] = temp; 
}

void PriorityQueue::decrease_key(PriorityQueueItem *item, int new_key) {
    if (new_key >= item->key) {
        return;
    }
    int i = 0;
    for (i = 0; i < q.size(); i++) {
        if (item == &q[i]) {
            break;
        }
    }
    if (i == q.size()) {
        return;
    }
    q[i].key = new_key;
    while (i > 0 && q[PARENT(i)].key > q[i].key) {
        exchange(i, PARENT(i));
        i = PARENT(i);
    }
}