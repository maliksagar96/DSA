/*
  Kadan's algorihthm for non circular array.

  At every step we check if the currentNum is bigger or currNum + currentSum is bigger, whichever is bigger we put that equal to the currentSum. 
  Then this currentSum is compared with the maxSum. Whichever is bigger that is the bigger sum. 

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumSubArray(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];

    int maxSum = nums[0];
    int currSum = nums[0];

    for(int i = 1;i<nums.size();i++) {
      currSum = max(nums[i], currSum + nums[i]);
      maxSum = max(maxSum, currSum);
    }

    return maxSum;

  }

};

int main() {

  // vector<int> nums = {1, -2, 3, -2};
  // vector<int> nums = {8, -1, 3, 4};
  vector<int> nums = {10, -12, 11, -3, 4, -2, 6, -15, 8, 9, -4, 3, -1, 2, -6};
  
  

  Solution sol;

  cout << sol.maxSumSubArray(nums) << endl;

  return 0;
}
