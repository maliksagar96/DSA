/*
  Kadan's algorihthm for circular array.

  We have to implement the maxsum subarray along with minsum subarray. 
  Why finding a minimum sum, because we are finding a small subarray which is like a bad patch. 

*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumcircularArray(vector<int>& nums) {
    if(nums.size() == 1) return nums[0];

    int maxSum = nums[0];
    int currSum = nums[0];
    int minSum = nums[0];
    int currMinSum = nums[0];
    int total = nums[0];


    for(int i = 1;i<nums.size();i++) {
      total += nums[i];
      
      currSum = max(nums[i], currSum + nums[i]);
      maxSum = max(maxSum, currSum);

      currMinSum = min(nums[i], currMinSum + nums[i]);
      minSum = min(minSum, currMinSum);

    }

    //In case of all negative values total - minSum = 0; Wrong answer. This if is to check for all the negative elements array.
    if (maxSum < 0)
      return maxSum;

    return max(maxSum, total-minSum);

  }

};

int main() {

  // vector<int> nums = {1, -2, 3, -2};
  // vector<int> nums = {8, -1, 3, 4};
  // vector<int> nums = {10, -12, 11, -3, 4, -2, 6, -15, 8, 9, -4, 3, -1, 2, -6};
  
  
  // vector<int> nums = {8, -8, 9, -9, 10, -11, 12};
  // vector<int> nums = {10, -3, -4, 7, 6, 5, -4, -1};
  vector<int> nums = {-3, -4, -4, -1};


  Solution sol;

  cout << sol.maxSumcircularArray(nums) << endl;

  return 0;
}
