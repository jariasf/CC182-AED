#ifndef _MAX_HEAP_H
#define _MAX_HEAP_H
#endif

class MaxHeap{
public:
    MaxHeap(int capacity);
    ~MaxHeap();
    void insert(int key);
    int extractMax();
    int getMax();
    bool isEmpty();

private:
    int *A;
    int heap_size; // Current number of elements in heap
    int capacity;  // Maximum possible size of heap
    int parent(int i);
    int left(int i);
    int right(int i);
    void maxHeapify(int i);
};