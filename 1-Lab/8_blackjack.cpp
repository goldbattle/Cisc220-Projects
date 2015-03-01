#include <iostream>
#include <stdlib.h>
#include <time.h>

bool next_round(int &score);
bool check_score(int &score);

// int main() {
//   // Random seed
//   srand(time(NULL));
//   // Declare our score
//   int score = 0;
//   // Start the round
//   if(next_round(score)) {
//     std::cout << "You WON with a score of, " << score << std:: endl;
//   } else {
//     std::cout << "You LOST with a score of, " << score << std:: endl;
//   }
//   // Return success
//   return 0;
// }

bool next_round(int &score) {
  // Check our current score
  if(!check_score(score)) {
    return false;
  }
  // Loop the game
  bool is_end = false;
  while(!is_end) {
    // Random card selection
    int random = rand() % 10 + 1;
    score += random;
    std::cout << "Rolled a: " << random << ", score is " << score << std:: endl;
    // Check score again
    if(!check_score(score)) {
      return false;
    }
    // Ask if we want to keep going
    std::cout << "Would you like to keep going? (yes/no)" << std:: endl;
    std::string input = "";
    std::cin >> input;
    // Stop going if input is no
    if(input == "no") {
      return true;
    }
  }
  return true;
}

bool check_score(int &score) {
  // Check if we are at max score
  if(score > 21) {
    return false;
  }
  return true;
}