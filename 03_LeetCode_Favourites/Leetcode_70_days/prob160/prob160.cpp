/*

This is an easy one. Travere the whole list A by a and whole list B by b. Then when the lists finish 
point the a to headB and point b to headA. They will travel same distance at every iteration and at one
iteration they'll meet. Return this. 

*/


#include <iostream> 

using namespace std;

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
      if(!headA || !headB)  return nullptr;

      ListNode *a = headA;
      ListNode *b = headB;

      while(a!=b) {
        if(a) a = a -> next;
        else a = headB;

        if(b) b = b->next;
        else b = headA;        
      }

      return a;

    }
};


int main() {

  return 0;
}