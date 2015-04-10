#ifndef NODE_HPP_
#define NODE_HPP_
class Node {
  // friend means private fields and methods can be accessed by methods in the class LL
  friend class LL;
  int data;
  int priority;
  Node *next;
  public:
  Node(int x, int y);
  Node(int x);
  ~Node();
  void printNode();
};
#endif /* NODE_HPP_ */
