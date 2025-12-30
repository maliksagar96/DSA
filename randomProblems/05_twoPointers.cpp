#include <iostream>
using namespace std;

struct Node {
  int val;
  Node* next;

  Node(int v) : val(v), next(nullptr) {}
};

int main() {

  // Create nodes
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  // Create a cycle: 5 -> 3
  head->next->next->next->next->next = head->next->next;

  // TODO:
  // Write fast and slow pointer logic here
  // to detect cycle

  Node *fast = head;
  Node *slow = head;

  while(fast && fast->next) {
    fast = fast->next->next;
    slow = slow->next;

    if(fast == slow) {
      cout<<"The linkedlist has a loop.\n"<<endl;
      break;
    }
  }

  return 0;
}
