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

    ListNode* reverselist(ListNode* head) {
      ListNode* next = nullptr;
      ListNode* prev = nullptr;
      ListNode* curr = head;

      while(curr) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
      }

      return prev;
    }

    ListNode* cutList(ListNode* head, int left, int right) {
      
      ListNode* leftList = head;
      int counter = 0;
      while(left < counter) {
        leftList = leftList->next;
        counter++;
      }
      ListNode* middleList = leftList->next;
      leftList->next = nullptr;

      

      ListNode* cutList = head;
      while(counter < pos) {
        cutList = head->next;
        counter++;
      }
      
      cutList->next = nullptr;
      return cutList;

    }

    ListNode* reverseBetween(ListNode* head, int left, int right) {
      
    }
};

int main() {

  return 0;
}