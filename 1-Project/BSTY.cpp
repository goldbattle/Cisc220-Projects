#include <string>
#include <iostream>
#include <iomanip>
#include "BSTY.h"
#include "NodeTY.h"

using namespace std;

BSTY::BSTY() {
    // Set the default root
    this->root = NULL;
}

BSTY::~BSTY() {
    // Don't have to do this cleanup
    // Only read the tree in once, and never delete it
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

// Pass the pointer in  by address so we can update it
// This recurses until it finds a null value, then it sets that to the node of interest
// On return it updates the height based on the height() function
bool BSTY::insert(string x, NodeTY*& n) {
    // End condition
    if(n == NULL) {
        n = new NodeTY(x);
        return true;
    }
    // Left side sort
    else if(x < n->data) {
        this->insert(x, n->left);
        // Balance if unequal
        if(getHeight(n->left) - getHeight(n->right) == 2) {
            // If we are still correct we just need to rotate once
            if(x < n->left->data)
                leftRot(n);
            else
                leftLeftRot(n);
        }
        return true;
    }
    // Right side sort
    else if(x > n->data) {
        this->insert(x, n->right);
        // Balance if unequal
        if(getHeight(n->left) - getHeight(n->right) == -2) {
            // If we are still correct we just need to rotate once
            if(x > n->right->data)
                rightRot(n);
            else
                rightRightRot(n);
        }
        return true;
    }
    return false;
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

void BSTY::leftRot(NodeTY*& n) {
    NodeTY* temp = n->left;
    n->left = temp->right;
    temp->right = n;
    n = temp;
}

void BSTY::rightRot(NodeTY*& n) {
    NodeTY* temp = n->right;
    n->right = temp->left;
    temp->left = n;
    n = temp;
}

void BSTY::rightRightRot(NodeTY*& n) {
    leftRot(n->right);
    rightRot(n);
}

void BSTY::leftLeftRot(NodeTY*& n) {
    rightRot(n->left);
    leftRot(n);
}

int BSTY::getHeight(NodeTY* n) {
    // At the end
    if(n==NULL)
        return 0;
    // Recurse down, and compare the left right bal
    int l_height = getHeight(n->left);
    int r_height = getHeight(n->right);
    // Return back up our height
    if(l_height > r_height)
        return 1+l_height;
    else
        return 1+r_height;
}
