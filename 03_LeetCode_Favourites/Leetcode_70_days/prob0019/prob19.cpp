#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
  public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode* temp = head;
    int counter = 0;
    while(temp != nullptr) {
      temp = temp->next;
      counter++;          
    }

    if(counter == n) 
      return head->next;
    
    int popCounter = 0;
    temp = head;
    while(popCounter < counter - n - 1) {
      temp = temp->next;
      popCounter++;
    }
    
    ListNode *nextNode = temp->next;
    temp->next = temp->next->next;
    delete nextNode;
    return head;
  }
  };

int main() {

  
  return 0;
}