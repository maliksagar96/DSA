/*

So I will only write the easy picture to do this. If problem 21 is not attempted now is the time to attempt it. 

1) We need to recursively call the sortfunction. Keep splitting the List into half every time.One will be left and other right.
2) Then at the end there will be just 2 elements in the left and right lists. 
3) Then sort the single linked lists and then merge them to make 2. 
4) Now you have 2 lists 2 elements long. Now all the follow up is problem 21. 

*/


#include <iostream> 

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
  ListNode* findmiddle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = nullptr;

    while (fast && fast->next) {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    if (prev) prev->next = nullptr; // split the list
    return slow;
  }

  ListNode* mergeList(ListNode* left, ListNode* right) {
    ListNode dummy(0);
		ListNode *tail = &dummy;
		
		
		while(left && right){
		
			if(left->val < right->val) {				
				tail->next = left;
				left = left->next;				
			}
			
			else{
				tail->next = right;
				right = right->next;					
			}		
			
			tail = tail->next;	
		}
		
		if(left) {
			tail->next = left;
		}
		
		else {
			tail->next = right;
		}
		
		return dummy.next;
  }

  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head; // base case

    ListNode* mid = findmiddle(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);

    return mergeList(left, right);
  }
};


int main() {

  return 0;
}