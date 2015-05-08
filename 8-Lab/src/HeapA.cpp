#include <iostream>
#include "HeapA.hpp"

using namespace std;

HeapA::HeapA(int len) {
    this->length = len;
    this->data = new int[len];
    this->cur_pos = -1;
}

void HeapA::insert(int num) {
    // Check end
    if(cur_pos == length)
        return;
    // Increase
    cur_pos++;
    // Add to end child
    data[cur_pos] = num;
    // Bubble
    bubble_up(cur_pos);
}

int HeapA::pop_heap() {
    // Check end
    if(cur_pos == -1)
        return -1;
    // Move end
    int temp = data[0];
    data[0] = data[cur_pos];
    data[cur_pos] = 0;
    // Decrease
    cur_pos--;
    // Bubble down
    bubble_down(0);
    // Return
    return temp;
}

void HeapA::print_heap() {
    for(int c=0; c < cur_pos; c++) {
        cout << data[c] << " ";
    }
    cout << endl;
}

void HeapA::bubble_up(int pos) {
    // If back at root or invalid spot
    if(pos < 0 || (pos-1)/2 < 0)
        return;
    // Check if our parent is smaller then ourselves
    if(data[(pos-1)/2] < data[pos]) {
        int temp = data[(pos-1)/2];
        data[(pos-1)/2] = data[pos];
        data[pos] = temp;
        // Recurse
        bubble_up((pos-1)/2);
    }

}

void HeapA::bubble_down(int num) {
    // Children
    int right = 2*num + 2;
    int left = 2*num + 1;
    // End case
    if(right > cur_pos || left > cur_pos)
        return;
    // If we should switch
    if(data[right] > data[left] && data[right] > data[num]) {
        //cout << "Going right: " << right << ", " << left << endl;
        int temp = data[num];
        data[num] = data[right];
        data[right] = temp;
        // Recurse
        bubble_down(right);
    }
    else if(data[left] > data[num]) {
        //cout << "Going left: " << right << ", " << left << endl;
        int temp = data[num];
        data[num] = data[left];
        data[left] = temp;
        // Recurse
        bubble_down(left);
    }
}
