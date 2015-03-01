#include <iostream>

int problem_4(int);

// int main() {
//   int x = 0;
//   int y = 0;
//   // Ask for input
//   std::cout << "Please enter a positive number: ";
//   // Read the input from the console
//   std::cin >> x;
//   // Ask for input
//   std::cout << "Please enter a larger number: ";
//   // Read the input from the console
//   std::cin >> y;
//   // Loop through each number between the ones entered
//   for(int i=x; i<=y; i++) {
//     // Call our function
//     problem_4(i);
//     // Debug
//     //std::cout << count << " " << isdigit(count) << " ";
//     // Output success
//     std::cout << "Collatz Conjecture is still working" << std::endl;
//   }
//   // Return success
//   return 0;
// }

int problem_4(int x) {
  int count = 0;
  // Loop till negative
  while(x > 1) {
    // Add to our count
    count++;
    // If even, divide by 2
    if(x%2 == 0) {
      x /=2;
    }
    // If odd times 3, add 1
    else {
      x = x*3 + 1;
    }
  }
  // Return
  return count;
}