/*
 This I found is a straight forward problem if you understand the logic and draw it out by hand. 

 Let do one step by step. 

 1-2-3-4-5-6. => original list. 

 Final target = 1-5-4-3-2-6. I reversed the 2-5 list. 

 So the logic is to insert 3 between 1 and 2. Then insert 4 between 1 and 3. Then insert 5 between 1 and 4. 
 This is the most efficient way apparently. The other is bubble sort. Which is actually harder to code.(Give it a try maybe)
 

 Iteration 1:
 What we want. We want 3 steps.
 1) 2->4. 
 2) 3->2. 
 3) 1->3. 

 Think about these steps. This is all we need. This is it.

 While doing this the left list and the right list will remain fixed. No changes. 

 So lets name prev = one. (fixed)

 curr = prev->next. 
 toMove = curr->next.

 Now prev = 1
     curr = 2
     toMove = 3

we'll move 3 to 2. 
 
step 1) 2->4 = curr->next = toMove->next.
step 2) 3->2 = toMove->next = prev->next. 
step 3) 1->4 = prev->next = toMove.


These 3 steps will be repeated again and again. (4 actually, setting curr->next = toMove)

Do these steps by hand and you'll get the answer.
 */

#include <iostream>

using namespace std;

class ListNode{
  public:
    int val;
    ListNode *next;

    ListNode():val(0), next(nullptr){}
    ListNode(int x):val(x), next(nullptr){}
    ListNode(int x, ListNode *next):val(x), next(next){}
};

int main(){
  ListNode *six = new ListNode(6);
  ListNode *five = new ListNode(5, six);
  ListNode *four = new ListNode(4, five);
  ListNode *three = new ListNode(3, four);
  ListNode *two = new ListNode(2, three);
  ListNode *one = new ListNode(1, two);

  ListNode *head = one;

  while(head) {
    cout<<"head->val = "<<head->val<<endl;
    head = head->next;
  }

  ListNode* dummy = new ListNode(0, one); // handle head safely
  ListNode* prev = dummy;

  // Move prev to node before 2
  prev = one;  // prev = 1
  ListNode* curr = prev->next; // curr = 2
  ListNode* temp = curr->next; // temp = 3

  // Swap step (same as first iteration in reverseBetween)
  curr->next = temp->next;     // 2 → 4
  temp->next = prev->next;     // 3 → 2
  prev->next = temp;           // 1 → 3

  

  // Optional: update 'one' if needed (since head hasn't changed)
  temp = dummy->next;
  while (temp) {
      cout << temp->val <<endl;
      temp = temp->next;
  }
  cout << endl;


  delete six;
  delete five;
  delete four;
  delete two;
  delete three;
  delete one;

  return 0;
}