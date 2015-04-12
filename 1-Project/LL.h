#ifndef LL_H_INCLUDED
#define LL_H_INCLUDED
#include "NodeL.h"
#include <string>

using namespace std;

class LL {

  Node *first;
  Node *last;
  int currsize;

  public:
      LL(); //constructor
      ~LL(); //destructor
      int size(); // returns the current size of the list
      void push(string str); //adds new node to end of list
      void remove(Node *n); // removes node n from the list
      string get(int x); // Get's a node at a key index
      void printList();
};

#endif // LL_H_INCLUDED
