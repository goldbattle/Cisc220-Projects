#include <iostream>

void problem_4(char a[], char b, char c, int len) {
  // Loop through the array
  for (int i=0; i<len; i++) {
    // Replace if we match
    if(a[i] == b) {
      a[i] = c;
    }
  }
}

void print_array(char *a, int len) {
  // Loop through the array
  for (int i=0; i<len; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
}

char * problem_5(char a[], char b, int len) {
  // New array's length
  int i = 0;
  int new_len = len;
  // Loop through the array
  for (i=0; i<len; i++) {
    // Replace if we match
    if(a[i] == b) {
      new_len--;
    }
  }
  // New size
  //std::cout << new_len << std::endl;
  // New array, allocate mem
  char *c = new char [len];
  // Loop through the array, backwards
  for (i=len-1; i>=0; i--) {
    // Replace if we match
    if(a[i] != b) {
      c[new_len-1] = a[i];
      new_len--;
    }
  }
  // Return
  return c;
}