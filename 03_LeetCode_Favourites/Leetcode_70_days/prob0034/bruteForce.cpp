/*
  Brute force for this problem is quite straightforward. No major issues. However I am wondering if i can improve on the brute force logic as well. 
  I am looking for a better brute force logic.
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> minMax(2,-1);
      bool minFlag = true;
      for(int i = 0;i<nums.size();i++) {
        if(nums[i] == target && minFlag){
          minMax[0] = i;
          minMax[1] = i;
          minFlag = false;          
          continue;
        } 
        if(nums[i] ==  target) {
          if(minMax[1]<i) minMax[1] = i;
        } 

      }
      return minMax;
    }
};

int main() {

  vector<int> nums = {5,7,7,8,8,10};
  Solution sol;
  
  sol.searchRange(nums, 8);

  return 0;
}