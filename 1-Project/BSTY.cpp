#include <string>
#include <iostream>
#include <iomanip>
#include "BSTY.h"
#include "NodeTY.h"

using namespace std;

BSTY::BSTY() {
    this->root = NULL;
}

BSTY::~BSTY() {

}

bool BSTY::insert(string x) {
    // Add the root if needed
    if(this->root == NULL) {
        root = new NodeTY(x);
        return true;
    }
    // Do it normally
    return this->insert(x, root);
}

bool BSTY::insert(string x, NodeTY *n) {
    // Add the root if needed
    if(this->root == NULL) {
        this->root = n;
        return true;
    }
    // Sort left side
    if(x <= n->data) {
        // If null, just insert it
        if(n->left == NULL) {
            n->left = new NodeTY(x);
            return true;
        }
        else {
            return this->insert(x, n->left);
        }
    }
    // Sort the right side
    else {
        // If null, just insert it
        if(n->right == NULL) {
            n->right = new NodeTY(x);
            return true;
        }
        else {
            return this->insert(x, n->right);
        }
    }
    return true;
}


void BSTY::printTreeio() {
    // Call our recursive method
    printTreeio(root);
}

void BSTY::printTreeio(NodeTY *n) {
    // If we are a leaf, return back up
    if(n == NULL) {
        return;
    }
    // Go left
    if(n->left != NULL)
        printTreeio(n->left);
    // Print root
    cout << n->data << endl;
    // Go right
    if(n->right != NULL)
        printTreeio(n->right);

}

bool BSTY::search(string x) {
    // Search starting at the root
    return this->search(root, x);
}

bool BSTY::search(NodeTY *n, string x) {
    // Check if we are a leaf
    if(n == NULL) {
        return false;
    }
    //cout << n->data << " : with : " << x << " " << (n->data == x) << endl;
    // Check if we match at all
    if(n->data == x) {
        return true;
    }
    // Go left or right as needed
    if(x < n->data) {
        return this->search(n->left, x);
    } else {
        return this->search(n->right, x);
    }

}
