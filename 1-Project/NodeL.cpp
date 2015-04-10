#include "NodeL.h"
#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

Node::Node(string str) {
  data = str;
  next = NULL;
}
Node::~Node() {
  if (next != NULL) {
    cout << "deleting this node may cause a memory leak" << endl;
  }
}
void Node::printNode() {
  cout << "|"<< data << "|";
}
