/*

This is my first hard problem of leetcode which I have done successfully and without any help. This is a straight forward problem if you do problem 92 first.
If one has a good understanding of prob 92 then this is a piece of cake.

*/



#include <iostream>

using namespace std;  

class ListNode {
  public:
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}  
};

class Solution {
  public:
    ListNode* reverseKGroup(ListNode* head, int k) {
      ListNode *dummy = new ListNode(-1, head);
      ListNode *prev = dummy;
      while(1) {
        ListNode *curr = prev->next;
        ListNode *check = curr;

        for(int i = 0;i<k;i++) {
          if(!check) return dummy->next;
          check = check->next;
        }


        for(int i = 0;i<k-1;i++) {
        ListNode *toMove = curr->next;
        curr->next = toMove->next;
        toMove->next = prev->next;
        prev->next = toMove;
        }
        prev = curr;
      } 
      

      return dummy->next;

    }
};


int main() {

  ListNode *six = new ListNode(6);
  ListNode *five = new ListNode(5, six);
  ListNode *four = new ListNode(4, five);
  ListNode *three = new ListNode(3, four);
  ListNode *two = new ListNode(2, three);
  ListNode *one = new ListNode(1, two);

  return 0;
}