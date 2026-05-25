#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class ListNode {
public:
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  bool hasCycle(ListNode *head) {
    if((head == nullptr) || (head->next == nullptr)) return false;

    ListNode* slow = head;
    ListNode* fast = head;

    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast) return true;
    }    
    
    return true;
  }
};


int main(){

  // Example usage of the Solution class
  Solution sol;
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = head; // Creating a cycle for testing


  return 0;
}