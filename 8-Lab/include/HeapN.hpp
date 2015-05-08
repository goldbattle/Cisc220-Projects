#ifndef HEAPN_H
#define HEAPN_H
#include "NodeN.hpp"


class HeapN {

    NodeN* root;
    NodeN* last;
    int height;
    int fullness;

    public:
        HeapN();
        void insert(int num);
        int pop_heap();
        void print_heap();
    private:
        void print_heap(NodeN *n);
        void insert(NodeN*& to_add, NodeN*& parent, NodeN*& cur, int full, int max);
        void bubble_up(NodeN* next);
        //void bubble_down(HeapN& next);
};

#endif // HEAPN_H
