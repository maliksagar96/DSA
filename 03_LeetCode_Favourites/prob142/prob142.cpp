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
  
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return nullptr;

    ListNode* slow = head;
    ListNode* fast = head->next;
    while(fast != nullptr && fast->next != nullptr) {      
      slow = slow->next;
      fast = fast->next->next;
      if(slow == fast) break;
    }    

    if(slow == fast) {
      slow = head;
      while(slow != fast){
        slow = slow->next;
        fast = fast->next;
      }
      return slow; // The start of the cycle
    }
    return nullptr; // No cycle detected
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