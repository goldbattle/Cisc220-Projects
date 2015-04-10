#ifndef LAB3LOTTERY_HPP
#define LAB3LOTTERY_HPP

struct Customer {
  int id;
  int num_tickets;
  int** tickets;
};

struct Store {
  int id;
  int num_customers;
  int num_sold;
  Customer* customers;
  int num_winners[3] = {0,0,0};
};

struct Owner {
  int num_stores;
  int num_sold;
  int total_winners[3] = {0,0,0};
  Store* stores;
};

Owner *makeOwner();
Store makeStore();
Customer makeCustomer();
void getWinners (int winners[]);
int checkwin(int *nums, int *winners);
void findWinners(Owner *owner, int *ls);


#endif //LAB3LOTTERY_HPP

