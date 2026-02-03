#include <iostream>

using namespace std;

class ListNode{
  int val;
  ListNode* next;
  ListNode():val(0), next(nullptr) {}
  ListNode(int x):val(x), next(nullptr) {}
  ListNode(int x, ListNode* next): val(x), next(next) {}
};

class Solution {
public:

    ListNode* reverseBetween(ListNode* head, int left, int right) {
      if(!head || left = right) return head;

      ListNode* dummy = new ListNode(-1, head);

      ListNode *prev = dummy;

      for(int i = 1;i<left;i++) {
        prev = prev->next;
      }

      ListNode *curr = prev->next;
      for(int i = 0;i<right-left;i++) {
        ListNode *toMove = curr->next;
        curr->next = toMove->next;
        toMove->next = prev->next;
        prev->next = toMove;
      }

      return dummy->next;

    }
};

int main() {

  return 0;
}