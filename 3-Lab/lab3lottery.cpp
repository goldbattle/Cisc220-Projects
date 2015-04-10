#include <iostream>
#include <stdlib.h>
#include <time.h>

#include "lab3lottery.hpp"

using std::cout;
using std::endl;

Owner *makeOwner() {
  // Our owner
  Owner* o = new Owner;
  // Number between 1 and 10
  int ran = rand() % 10 + 1;
  // Update our owner
  o->num_stores = ran;
  o->num_sold = 0;
  o->stores = new Store[ran];
  // Create that many stores
  for (int i = 0; i < ran; i++) {
    o->stores[i] = makeStore();
    o->num_sold += o->stores[i].num_sold;
  }
  // Return
  return o;
}

Store makeStore() {
  // Our store
  Store* s = new Store;
  // Number between 100 and 1
  int ran_1 = rand() % 100 + 1;
  int ran_2 = rand() % 10 + 1;
  // Update the store
  s->id = ran_1;
  s->num_sold = 0;
  s->num_customers = ran_2;
  s->customers = new Customer[ran_2];
  // Create customers
  for (int i = 0; i < ran_2; i++) {
    s->customers[i] = makeCustomer();
    s->num_sold += s->customers[i].num_tickets;
  }
  // Return
  return *s;
}

Customer makeCustomer() {
  // OUr customer
  Customer* c = new Customer;
  // Number between 100 and 1
  int ran_1 = rand() % 1000 + 1;
  int ran_2 = rand() % 20 + 1;
  // Update our customer's props
  c->id = ran_1;
  c->num_tickets = ran_2;
  c->tickets = new int*[ran_2];
  // Temp array
  int* temp;
  // Create tickets
  for (int i = 0; i < ran_2; i++) {

    int ran_3 = rand() % 9;
    int ran_4 = rand() % 9;
    int ran_5 = rand() % 9;

    // Store the tickets
    temp = new int[3];
    temp[0] = ran_3;
    temp[1] = ran_4;
    temp[2] = ran_5;
    // Add to array
    c->tickets[i] = temp;
  }
  // Return
  return *c;
}

void getWinners (int winners[]) {
  int ran_1 = rand() % 9;
  int ran_2 = rand() % 9;
  int ran_3 = rand() % 9;
  winners[0] = ran_1;
  winners[1] = ran_2;
  winners[2] = ran_3;
}

int checkwin(int *nums, int *winners) {
  int count = 0;
  if(nums[0] == winners[0])
    count++;
  if(nums[1] == winners[1])
    count++;
  if(nums[2] == winners[2])
    count++;
  return count;
}

void findWinners(Owner *owner, int *ls) {
  // Stores
  for (int i = 0; i < owner->num_stores; i++) {
    cout << "Store: " << owner->stores[i].id << " Number Sold: " << owner->stores[i].num_sold << endl;
    // Store win count
    int win_count = 0;
    // Customers
    for (int z = 0; z < owner->stores[i].num_customers; z++) {
      cout << "   Customer: " << owner->stores[i].customers[z].id << endl;
      // Tickets
      for (int y = 0; y < owner->stores[i].customers[z].num_tickets; y++) {
        cout << "      Ticket: [";
        // Print ticket nums
        for (int c = 0; c < 3; c++) {
          cout << owner->stores[i].customers[z].tickets[y][c];
        }
        // How much we won
        int won = checkwin(owner->stores[i].customers[z].tickets[y], ls);
        // Update our counts
        win_count += won;
        if(won == 1) {
            owner->stores[i].num_winners[0]++;
            owner->total_winners[0]++;
        }
        if(won == 2) {
            owner->stores[i].num_winners[1]++;
            owner->total_winners[1]++;
        }
        if(won == 3) {
            owner->stores[i].num_winners[2]++;
            owner->total_winners[2]++;
        }
        cout << "] - Matched " << won << endl;
      }
    }
    // Total for the store
    cout << "   Total count for store: " << win_count << " (" << owner->stores[i].num_winners[0] << "," << owner->stores[i].num_winners[1] << "," << owner->stores[i].num_winners[2] << ")" << endl;
  }
}
