#include "Test.h"
#include <iostream>

using namespace std;

Test::Test() {
    this->num_1 = new int(0);
    this->num_2 = new double(0);
    this->next = NULL;
    this->prev = NULL;
}

Test::Test(int num) {
    this->num_1 = new int(num);
    this->num_2 = new double(0);
    this->next = NULL;
    this->prev = NULL;
}

Test::Test(int num_1, double num_2) {
    this->num_1 = new int(num_1);
    this->num_2 = new double(num_2);
    this->next = NULL;
    this->prev = NULL;
}

void Test::print() {
    cout << "num_1 = " << *num_1 << endl;
    cout << "num_2 = " << *num_2 << endl;
    cout << "next = " << next << endl;
    cout << "prev = " << prev << endl;
    cout << "\n" << endl;
}


int main() {
    Test* temp0 = new Test();
    temp0->print();
    Test* temp1 = new Test(1);
    temp1->print();
    Test* temp2 = new Test(1,2.2);
    temp2->print();
}
