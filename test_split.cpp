/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include <iostream>

int main(int argc, char* argv[])
{
  Node* head = nullptr;

  for (int i = 1; i <= 5; i++) { 
    head = new Node(i, head); 
  }

  Node* temp = head;
  std::cout << "List: "; 
  while(temp != nullptr) {
    std::cout << temp->value << " "; 
    temp = temp->next; 
  }


  Node* odds = nullptr; 
  Node* evens = nullptr; 
  split(head, odds, evens); 

  temp = odds; 
  std::cout << "Odds: "; 
  while (temp != nullptr) { 
    std::cout << temp->value << " "; 
    temp = temp->next; 
  }
  
  temp = evens; 
  std::cout << "Evens: "; 
  while (temp!= nullptr) { 
    std::cout << temp->value << " "; 
    temp = temp->next; 
  }
  
}
