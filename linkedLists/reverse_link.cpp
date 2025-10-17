#include <iostream>

using namespace std;

class Node{

  public:
    Node():value(-1), next(nullptr){}

    int value;
    Node *next;
  
};

int main() {

  Node* first  = new Node();
  Node* second = new Node() ;
  Node* third  = new Node();

  first->value = 10;
  second->value = 20;
  third->value = 30;
  
  first->next = second;
  second->next = third;



  Node* temp = first;
  while(temp!= nullptr) {
    cout<<temp->value<<endl;
    temp = temp->next;
  }


  Node* prev = nullptr;
  Node* next = nullptr;
  Node* curr = first;

  while(curr!=nullptr) {
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  Node* temp_rev = third;
  while(temp_rev!= nullptr) {
    cout<<temp_rev->value<<endl;
    temp_rev = temp_rev->next;
  }
 
  delete first;
  delete second;
  delete third;

  return 0;
}