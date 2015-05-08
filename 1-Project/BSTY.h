#ifndef BSTY_H_INCLUDED
#define BSTY_H_INCLUDED
#include <string>
#include "NodeTY.h"

using namespace std;

class BSTY {

    NodeTY *root;

    public:
        BSTY(); // constructor – sets root to NULL
        ~BSTY(); // destructor – deletes tree
        bool insert(string x);
        /* recursively inserts x into the tree with the current root (possibly of a
        subtree) being n */
        bool insert(string x, NodeTY*& n);
        /* Note the overloading of methods – this is needed if you choose to write
        this method recursively */
        void printTreeio();
        /* prints out the data in the tree in order (this should print out the
        dictionary alphabetically ) */
        void printTreeio(NodeTY *n);
        /* again, needed if you choose recursion bool search(string x); */
        bool search(string x);
        /* searches tree for x – returns true if found, false otherwise */
        bool search(NodeTY* n, string x);
    // AVL Tree functions
    private:
        // This rotates left around the passed node
        void leftRot(NodeTY*& n);
        // This rotates right around the passed node
        void rightRot(NodeTY*& n);
        // Does a left rotation around the right node, then a full right rotation
        void rightRightRot(NodeTY*& n);
        // Does a right rotation about the left node, then a full left rotation
        void leftLeftRot(NodeTY*& n);
        // recursive function to grab the current height of the node
        int getHeight(NodeTY* n);

};

#endif // BSTY_H_INCLUDED
