#ifndef NODEL_H_INCLUDED
#define NODEL_H_INCLUDED
#include <string>

using namespace std;

class Node {
  // friend means private fields and methods can be accessed by methods in the class LL
  friend class LL;

  string data;
  Node *next;

  public:
      Node(string str);
      ~Node();
      void printNode();
};

#endif // NODEL_H_INCLUDED
