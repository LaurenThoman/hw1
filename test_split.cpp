/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

void delL(Node*& head){ //deletes list
  while (head){
    Node* temp = head;
    head = head->next;
    delete temp;
  }
}

void printL(Node*& head){ //prints list
  Node* curr = head;
  while(head){
    std::cout << curr->value << "->";
    curr = curr->next;
  }
  std::cout << "nullptr" << std::endl;
} 

Node* createL(int arr[], int s){  //creates list
  if (s == 0){
    return nullptr;
  }
    Node* head = new Node{arr[0], nullptr};
    Node* cur = head;

  for(int i=1; i < s; i++){
    cur->next = new Node{arr[i], nullptr};
    cur = cur->next;
  }
  return head;
}


int main(int argc, char* argv[])
{
  int vals[] = {1, 2, 3, 4, 5, 6};
  Node* in = createL(vals, 6);
  Node* o = nullptr;
  Node* e = nullptr;

  //prints og list
  std::cout << "INTIAL LIST";
  printL(in);

  //SPLITS List
  split(in, o, e);

  //prints odd list
  printL(o);

  //prints even list
  printL(e);

  //handles memory
  delL(o);
  delL(e);
  
  return 0;
}
