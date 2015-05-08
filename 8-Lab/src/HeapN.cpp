#include "HeapN.hpp"
#include "NodeN.hpp"
#include <iostream>
#include <math.h>

using namespace std;

HeapN::HeapN() {
    root = NULL;
    last = NULL;
    height = 0;
    fullness = 0;
}

void HeapN::insert(int num) {
    NodeN* to_add = new NodeN{num};
    // Add
    insert(to_add, root, root, fullness, floor(pow(2, height)));
    last = to_add;
    // Increase fullness
    fullness++;
    // Roll height over
    if(fullness > floor(pow(2, height))) {
        fullness = 0;
        height++;
    }
    // Bubble
    cout << "Bubble: " << to_add->data << endl;
    bubble_up(to_add);
}

void HeapN::insert(NodeN*& to_add, NodeN*& parent, NodeN*& cur, int full, int max) {
    // Base case, root
    if(cur == NULL) {
        cur = to_add;
        cur->parent = NULL;
    }
    // Check if left is needed
    else if(cur->left == NULL) {
        cur->left = to_add;
        cur->left->parent = parent;
    }
    // Check right
    else if(cur->right == NULL) {
        cur->right = to_add;
        cur->right->parent = parent;
    }
    // Else, recurse down
    else {
        // Recurse left if less then half
        if(full < max/2) {
            insert(to_add, cur, cur->left, full, max/2);
        }
        // Go right
        else {
            insert(to_add, cur, cur->right, full-max/2, max/2);
        }
        return;
    }
}

int HeapN::pop_heap() {
    int d = root->data;
    return d;
    fullness--;
    // Roll height back if needed
    if(fullness < floor(pow(2, height))) {
        height--;
        fullness = floor(pow(2, height));
    }
    NodeN* temp = NULL;

}


void HeapN::bubble_up(NodeN* next) {
    // Loop until our child is not greater any more
    while(next->parent != NULL) {
        cout << "looping" << next->data << endl;
        if(next->parent->data < next->data) {
            print_heap();
            cout << "Swapping: " << next->parent->data << " and " << next->data << endl;
            // Switch data points with parent
            int temp = next->parent->data;
            next->parent->data = next->data;
            next->data = temp;
            // Move up
            next = next->parent;
        } else {
            return;
        }

    }
    print_heap();
}

void HeapN::print_heap() {
    print_heap(root);
    cout << endl;
}

void HeapN::print_heap(NodeN *n) {
    // If we are a leaf, return back up
    if(n == NULL)
        return;
    // Go left
    print_heap(n->left);
    // Print root
    cout << n->data << ", ";
    // Go right
    print_heap(n->right);
}
