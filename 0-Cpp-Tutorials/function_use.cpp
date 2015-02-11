#include <iostream>

void test_me(int x);

// int main() {
//   // Call our function
//   test_me(99);
//   // Return success
//   return 0;
// }

// We can declare this after, because we forward declared
void test_me(int x) {
  using std::cout;
  using std::endl;
  cout << "Hello World!" << endl;
  cout << "I was passed the number: " << x << endl;
}