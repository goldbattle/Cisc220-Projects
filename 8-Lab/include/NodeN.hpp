#ifndef NODEN_H
#define NODEN_H


class NodeN {

    friend class HeapN;

    // Pointers
    NodeN* parent;
    NodeN* left;
    NodeN* right;

    // Our data
    int data;

    // Creator
    NodeN(int num);
};

#endif // NODEN_H
