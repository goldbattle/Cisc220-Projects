#include <iostream>

int main() {
  // a
  int a = 8;
  // b
  std::cout << &a << std::endl;
  // c
  int *b = &a;
  // d
  std::cout << *b << std::endl;
  // e
  std::cout << b << std::endl;
  // f
  std::cout << &b << std::endl;
  // g
  a = 6;
  // Prints out 6
  std::cout << *b << std::endl;
  // h
  int c = 12;
  // i
  b = &c;
  c = 0;
  // Prints out 0
  std::cout << *b << std::endl;
  // j
  b = &a;
  int **d = &b;
  // k
  a = 8;
  std::cout << **d << std::endl;
  // l
  std::cout << *d << std::endl;
  // m
  std::cout << *&d << std::endl;
  // n
  std::cout << **&d << std::endl;
  // Return success
  return 0;
}