#ifndef LL_HPP_
#define LL_HPP_
#include "Node.hpp"
class LL {
  Node *first;
  Node *last;
  int currsize;
  int timestamp;
  public:
  LL(); //constructor
  ~LL(); //destructor
  int size(); // returns the current size of the list
  void push(); //adds new node to end of list
  void remove(Node *n); // removes node n from the list
  // finds the first node in the list with the priority of x and returns it
  Node *findPriority(int x);
  void updatePriority(); //increases the priority of nodes in the first third of the list
  void printList(); // prints out the entire list
};
#endif /* LL_HPP_ */
