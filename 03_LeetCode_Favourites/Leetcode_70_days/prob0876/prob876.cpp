#include  <iostream>

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

class ListNode{
  public:
  int val;
  ListNode *next;
  ListNode(): val(0), next(nullptr){}
  ListNode(int x): val(x), next(nullptr){}
  ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
  public:
  ListNode* middleNode(ListNode* head) {
      ListNode *slow = head;
      ListNode *fast = head;

      while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
      }

      return slow;
  }

};

int main() {

  ListNode* fifth = new ListNode(50);
  ListNode* fourth = new ListNode(40, fifth);
  ListNode* third = new ListNode(30, fourth);
  ListNode* second = new ListNode(20, third);
  ListNode* head = new ListNode(10, second);

  Solution sol;
  sol.middleNode(head);
  
  delete fifth;
  delete fourth;
  delete third;
  delete second;
  delete first;

  return 0;
}