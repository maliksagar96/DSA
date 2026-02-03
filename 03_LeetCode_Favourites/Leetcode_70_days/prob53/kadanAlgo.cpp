/**
  This is Kadane's algo. 
  A very nice trick to declare max and min elements is to take the first element of the array as max or min. 

  This is where we start from. 
  1) Declare the first element as maxSum and currentSum. 
  2) Traverse the array from 2nd element onwards. 
  3) CurrentSum += nums[i]
  4) Now this will keep on adding the elements till that point. 
  5) This is the tricky step now. -> The sum till now is it the greatest sum yet?
  When we say currentSum = max(current element, currentElement + current Sum ) . 
  In this case if my first element is negative and second element is positive then the first element will never be considered.
  a) We add all the elements and extend the previous array. 
  b) We Start a new subarray at the current element. 

  Then there is another thing. Keep on adding numbers till you have a positive streak. If that breaks and your currentsum becomes negative, ditch it 
  and start a new subarray with a positive number. 
  For example:
  [-2, -3, 4, -1, -2, 1, 5, -3]

  The first subarray will start when we hit 4. This will go on unless and untill it becomes negative and hits a positive number  and start a new subarray or
  the positive streak keeps on going. 

  One more observation is there. The subarray will always start and end with a positive number if both positive and negative numbers are present. 
  If only the negtive numbers are present then the smallest negative number willl be the answer. 
  If only a single positive number is present then it is the answer. 
  
  Finally the sub array will be the array guarded by positive numbers with negative number in between but the sum of negative numbers should not exceed the 
  sum of positive number in between and standing guard.

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
