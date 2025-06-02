#include <iostream> 

using namespace std;

class Node{
  public:
    int data;
    Node* next;
};


int main() {

  Node* first = new Node();
  Node* second = new Node();
  Node* third = new Node();

  first->data = 10;
  second->data = 20;
  third->data = 30;

  first->next = second;
  second->next = third;
  third->next = nullptr;

  Node* temp = first;

  while(temp != nullptr) {
    cout<<"data = "<<temp->data<<endl;
    temp = temp->next;
  }


  return 0;
}