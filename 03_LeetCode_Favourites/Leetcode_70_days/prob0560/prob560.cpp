/*
Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2

Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/

/*
  This is one the trickiest problems on leetcode. It is not so intuitive. 
  
  Here's the logic. 
  1) We have calucluate the prefix sum on the go. 
  Lets look at the example of 
  {1,2,3,-1,1,2,1,-2,4}
  Did a prefix sum, which came out to be. 
  We always start with the 0 as the first element of the prefix sum. In this one we'll maintain a hashmap to count the number of prefix sums. 
  Then we'll see if prefixSum - k is there? If it is then we'll add the frequency of that prefix sum in the answer. 
  {0, 1, 3, 6, 5, 6, 8, 9, 7, 11}. 

  So if you see the answer, the answers are
  1) {2,3}
  2) {1,2,3,-1}
  3) {2,1,-2,4}
  4) {2, 3, 1, -1}
  5) {3.-1.1.2}
  6) {-1,1,2,1,-2,4}
*/

#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> prefSumFreq;
    
    int cummulativeSum = 0;
    prefSumFreq[cummulativeSum] = 1;
    int n = nums.size();

    int counter = 0;

    for(int i = 0;i<n;i++) {
      cummulativeSum += nums[i];
      
      if(prefSumFreq.contains(cummulativeSum - k)) {
        counter += prefSumFreq[cummulativeSum - k];
      }

      prefSumFreq[cummulativeSum] += 1;
      
    }
    return counter;
  }
};


int main() {
  Solution sol;
  vector<int> nums = {1,2,3,-1,1,2,1,-2,4};
  // vector<int> nums = {0,0,0,0,0};
  sol.subarraySum(nums, 5);
  // cout<<sol.subarraySum(nums, 0)<<endl;
  return 0;
} 