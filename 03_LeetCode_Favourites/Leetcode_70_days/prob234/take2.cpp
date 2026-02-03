/*

Here's one way to do this. Apparently this is not the fastest. The fastest way to do this is to reach till the half of the list and 
then reverse the second half and compare the first and the second half.

This is an acceptable solution however it takes more time. 

Why does it take more time?
It is because using push_back creates new memory locations and this process will take time. Memory location on heap will take more time. 
Pointer manipulation is faster. 

*/

#include <iostream> 

using namespace std;

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    if(!head || !(head->next)) return true;
  
    ListNode *slow = head;
    ListNode *fast = head;

    while(fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    ListNode *prev = slow;
    ListNode *curr = prev;
    while(curr) {
      ListNode *toMove = curr->next;
      curr->next = toMove->next;
      toMove->next = prev->next;
      prev->next = toMove;
    }

    ListNode *left = head;
    ListNode *right = slow;

    while(left != right) {
      if(left->val != right->val) return false;      
      left = left->next;
      right = right->next;
    }

    return true;

  }

};


int main() {

  return 0;
}