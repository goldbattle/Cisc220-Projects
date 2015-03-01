#include <iostream>

bool is_correct_order(int &a, int &b, int &c);

// int main() {

//   int a = 2;
//   int b = 3;
//   int c = 4;
//   std::cout << "[" << a << "," << b << "," << c << "]" << std::endl;
//   std::cout << is_correct_order(a, b, c) << std::endl;
//   std::cout << "[" << a << "," << b << "," << c << "]" << std::endl;

//   a = 5;
//   b = 3;
//   c = 4;
//   std::cout << "[" << a << "," << b << "," << c << "]" << std::endl;
//   std::cout << is_correct_order(a, b, c) << std::endl;
//   std::cout << "[" << a << "," << b << "," << c << "]" << std::endl;

//   a = 3;
//   b = 2;
//   c = 1;
//   std::cout << "[" << a << "," << b << "," << c << "]" << std::endl;
//   std::cout << is_correct_order(a, b, c) << std::endl;
//   std::cout << "[" << a << "," << b << "," << c << "]" << std::endl;

//   // Return success
//   return 0;
// }

bool is_correct_order(int &a, int &b, int &c) {
  // Return value
  bool end = true;
  // Reorder a and b
  if(a>b) {
    int temp = a;
    a = b;
    b = temp;
    // Change our return
    end = false;
  }
  // Re-order b and c
  if(b>c) {
    int temp = b;
    b = c;
    c = temp;
    // Change our return
    end = false;
  }
  // Move last to the front if smallest
  if(c<a) {
    int temp1 = a;
    int temp2 = b;
    a = c;
    b = temp1;
    c = temp2;
    // Change our return
    end = false;
  }
  // return
  return end;
}
