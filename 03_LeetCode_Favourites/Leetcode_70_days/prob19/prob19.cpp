#include <stdio>

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
        bool popNode = true;
        ListNode* rmNode = head;
        int popCounter = 0;
        while(popNode) {
          if(popCounter == counter-n-1){
            rmNode->next = rmNode->next->next;
            break;
          }
          rmNode = rmNode->next;
          popCounter++;
        }
        return head;
      }
  };

int main() {

  
  return 0;
}