#include <iostream>
#include <algorithm>

int main() {
  std::cout << "Enter a number: ";
  int x;  
  // Read the input from the console
  std::cin >> x;
  std::cout << "You entered " << std::max(x,5) << std::endl;
  // Return success
  return 0;
}