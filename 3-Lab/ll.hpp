#ifndef LAB3_HPP_  // this makes sure that if you include this header file in more
                   // than one other file, the definitions won’t be repeated, wasting
                   // valuable compilation time…
#define LAB3_HPP_
#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>

using namespace std;

struct LL {
	string data;
	struct LL *next;
};

void insert(LL *x, LL *first, LL *second);
void traverse(LL *x);

#endif /* LAB3_HPP_ */
