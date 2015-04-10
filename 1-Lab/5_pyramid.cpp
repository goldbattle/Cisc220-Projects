#include <iostream>

int main() {
  int x = 0;
  int count = 0;
  // Ask for input
  std::cout << "Please enter a positive number: ";
  // Read the input from the console
  std::cin >> x;
  count = x;
  // Loop till negative
  while(count > 1) {
    // Update our count
    count--;
    // Move out to number
    for(int i=x-1; i > 0; i--) {
      std::cout << " ";
      if(i == x-count) {
        std::cout << x-count;
      }
    }
    // Add next set of spaces
    for(int i=(x-count)-2; i > 0; i--) {
      std::cout << " ";
    }
    // If we are not the first row, we add the next letter
    if((x-count)-1 > 0) {
      std::cout << x-count << std::endl;
    }
    // If in first row, just go to the next line
    else {
      std::cout << std::endl;
    }
  }
  // Add the last row
  for(int i=x*2-1; i > 0; i--) {
    std::cout << x;
  }
  // Return success
  return 0;
}