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
    vector<int> vals;
    while(head) {
      vals.push_back(head->val);      
      head = head->next;
    }  
    int left = 0, right = vals.size() - 1;
    while(left < right) {
      if(vals[left] != vals[right]) return false;
      left++;right--;

    }
    return true;
  }

};


int main() {

  return 0;
}