#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "HeapA.hpp"
#include "HeapN.hpp"

using namespace std;

int main() {
    // Rand
    srand(time(NULL));

    // Array version
    HeapA* heap_array = new HeapA{13};

    heap_array->insert(27);
    heap_array->insert(69);
    heap_array->insert(87);
    heap_array->insert(95);
    heap_array->insert(5);
    heap_array->insert(85);
    heap_array->insert(93);
    heap_array->insert(78);
    heap_array->insert(58);
    heap_array->insert(12);
    heap_array->insert(51);
    heap_array->insert(2);
    heap_array->insert(38);

    heap_array->print_heap();
    cout << "Popped heap: " << heap_array->pop_heap() << endl;
    heap_array->print_heap();
    cout << "Popped heap: " << heap_array->pop_heap() << endl;
    heap_array->print_heap();
    cout << "Popped heap: " << heap_array->pop_heap() << endl;
    heap_array->print_heap();

    // Node based implementation
    HeapN* heap_node = new HeapN{};
    heap_node->insert(27);
    heap_node->insert(69);
    heap_node->insert(87);
    heap_node->insert(95);
    heap_node->insert(5);
    heap_node->insert(85);
    heap_node->insert(93);
    heap_node->insert(78);
    heap_node->insert(58);
    heap_node->insert(12);
    heap_node->insert(51);
    heap_node->insert(2);
    heap_node->insert(38);

    heap_node->print_heap();

    // In this case, which do you prefer coding, the linked list or the array?
    // Doing an array is way better for handling a complete tree.
    // As you could tell, I could not logic through how to handle a complete tree
    // though node base elements.



    // Largest K element
    HeapA* heap_k = new HeapA{6};
    // Ask user
    cout << "Pick a number between 7 and 50" << endl;
    int temp = 0;
    cin >> temp;
    // Add the first 6 elements
     for(int i=0; i<7; ++i) {
        int x = rand()%100;
        cout << x << " ";
        heap_k->insert(x);
    }
    // Add the rest, remove the largest first, then add on
    for(int i=7; i<temp; ++i) {
        int x = rand()%100;
        cout << x << " ";
        heap_k->pop_heap();
        heap_k->insert(x);
    }
    // Get the 6th largest
    cout << endl << "6th Smallest Number: " << heap_k->pop_heap() << endl;

}
