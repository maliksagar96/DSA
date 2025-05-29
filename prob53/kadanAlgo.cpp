/**
  This is Kadane's algo. 
  A very nice trick to declare max and min elements is to take the first element of the array as max or min. 

  This is where we start from. 
  1) Declare the first element as maxSum and currentSum. 
  2) Traverse the array from 2nd element onwards. 
  3) CurrentSum += nums[i]
  4) Now this will keep on adding the elements till that point. 
  5) This is the tricky step now. -> The sum till now is it the greatest sum yet?
  


**/



#include <iostream> 
#include <vector> 

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0];  
        int currentSum = nums[0];
        for(int i = 1;i<nums.size();i++) {
          currentSum += nums[i];
          if(currentSum < nums[i]) currentSum = nums[i];
          if(maxSum < currentSum) maxSum = currentSum;
        }      
        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max SubArray Sum: " << sol.maxSubArray(nums) << endl;
    return 0;
}
