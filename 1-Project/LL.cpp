#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <string>

using namespace std;

#include "NodeL.h"
#include "LL.h"

LL::LL() {
  first = NULL;
  last = NULL;
  currsize = 0;
}

LL::~LL() {
  if (currsize > 0) {
    Node *temp = first;
    while (temp->next != NULL) {
      first = temp->next;
      temp->next = NULL;
      delete temp;
      temp = first;
    }
    delete temp;
    first = NULL;
    last = NULL;
    currsize = 0;
  }
}

int LL::size() {
  return currsize;
}

// (7 pts)
void LL::push(string str) {
  // Default
  if(first==NULL) {
    first = new Node(str);
    last = first;
    currsize = 1;
    return;
  }
  // Add a new one
  Node* temp = last;
  last = new Node(str);
  temp->next = last;
  currsize++;
  return;
}

//(14 pts)
void LL::remove(Node *n) {
  // Make sure we have an array
  if(first==NULL){
    return;
  }
  // Our temp
  Node* temp = first;
  // Check the first spot
  if(temp == n) {
    // Delete one long list
    if(temp->next == NULL) {
      delete temp;
      currsize--;
      first=NULL;
      last=NULL;
      return;
    } else {
      first = temp->next;
      temp->next = NULL;
      currsize--;
      delete temp;
    }
  }

  // Loop through the rest of them
  while (temp->next != NULL) {
    // See if we have a match
    if(temp->next==n) {
      Node* temp2 = temp->next;
      // Update next
      if(temp->next->next!= NULL) {
        temp->next = temp->next->next;
      } else {
        temp->next = NULL;
        last = temp;
      }
      // Fix start if needed
      if(temp2==first) {
        first = temp;
      }
      temp2->next = NULL;
      delete temp2;
      currsize--;
      return;
    }
    // Move down the line
    temp = temp->next;
  }
}

void LL::printList() {
  if (currsize > 0) {
    Node *temp = first;
    while (temp->next != NULL) {
      temp->printNode();
      cout<< "->";
      temp = temp->next;
    }
    temp->printNode();
    cout << endl;
    //cout << "here" << endl;
  }
  cout << "leaving printList " << endl;
  return;
}

