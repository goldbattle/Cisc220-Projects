#include <time.h>
#include <stdlib.h>
#include <iostream>
#include "lab3lottery.hpp"

using std::cout;
using std::endl;


int main() {
  srand(time(NULL));
  Owner *me= makeOwner();
  int winners[3] = {0,0,0};
  getWinners (winners);
  for (int i = 0; i < 3; i++) {
    cout << winners[i] << ",";
  }
  cout << endl;
  // Find the winners
  findWinners(me, winners);
  cout << "won with 1 number: "<< me->total_winners[0] << endl;
  cout << "won with 2 numbers: " << me->total_winners[1] << endl;
  cout << "won with 3 numbers: " << me->total_winners[2] << endl;
  return 0;
} //main


/*
#include <iostream>
#include <stdlib.h>
#include "ll.hpp"
//#include "lab3.hpp"

using namespace std;

int main() {
	LL *first;
	first = new LL;
	first->data = "bear";
	first ->next = NULL;

	LL *second;
	second = new LL;
	second->data = "echidna";
	second ->next = NULL;
	first->next = second;

	LL *third;
	third = new LL;
	third->data = "gerenuk";
	third ->next = NULL;
	second->next = third;

	LL *fourth;
	fourth = new LL;
	fourth->data = "wombat";
	fourth ->next = NULL;
	third->next = fourth;

	traverse(first);

	LL *fifth;
	fifth = new LL;
	fifth->data = "fossa";
	fifth ->next = NULL;

	insert(fifth, second, third);
	traverse(first);

	return 0;  // this has to be the last line in main

}//main
*/
