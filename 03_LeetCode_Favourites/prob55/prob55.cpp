/*
  We do this problem from the back of the array. We can ask if we can reach the end of the array from a step behind it. 
  That's the key intuition. 

  I have written 2 codes. One with the current pointer as a goal and a second one. I like the second one :) .

*/

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
// public:
//     bool canJump(vector<int>& nums) {
//       int sz = nums.size() - 1;
//       int goal = sz;
//       cout<< "goal = "<<goal << endl;

//       for(int i = sz-1;i >=0; i--) {
//         if(nums[i] + i >= goal) {
//           goal=i;
//         }        
        
//         cout<< "goal = "<<goal << endl;
//       }
      
//       return (goal == 0);
//     }
// };

/*Maybe one can like to read the following code. Goal is the dynamic size.*/
class Solution {
public:
    bool canJump(vector<int>& nums) {
      int sz = nums.size() - 1;
      int dynamic_size = sz;
      // cout<< "Dynamic size = "<<dynamic_size << endl;

      for(int i = sz-1;i >=0; i--) {
        int required_jumsize = dynamic_size-i;
        //current number should be larger then or equal to the jump size.
        if(nums[i] >= required_jumsize) {  
          dynamic_size=i;
        }        
        
        // cout<< "dynamic_size = "<<dynamic_size << endl;
      }
      
      return (dynamic_size == 0);
    }
};


int main() {

  vector<int> nums = {2, 0, 0};

  Solution sol;

  cout << sol.canJump(nums) << endl;

  return 0;
}