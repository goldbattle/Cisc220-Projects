#include <iostream>
#include <stdlib.h>

#include "ll.hpp"
//#include "lab3.hpp"

using namespace std;

void traverse(LL *ll) {
	LL *temp = ll;
	while (temp != NULL) {
		cout << temp->data <<endl;
		temp = temp->next;
	} //while
	cout << endl;
} //traverse

void insert(LL *x, LL *first, LL *second) {
  x->next = second;
  first->next = x;
}
