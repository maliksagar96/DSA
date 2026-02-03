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
  So this is one of the simpler problems on leet code.
  
  Here's the logic. 
  1) My first intuition did go towards prefix sum or cumulative sum technique. 
  I took the example of 
  {1,2,3,-1,1,2,1,-2,4}
  Did a cumulative sum, which came out to be. 
  {0(always keep the first element 0, very useful), }
  {0, 1, 3, 6, 5, 6, 8, 9, 7, 11}. 

  So if you see the answer, the answers are
  1) {2,3}
  2) {1,2,3,-1}
  3) {2,1,-2,4}
  4) {2, 3, 1, -1}
  5) {3.-1.1.2}
  6) {-1,1,2,1,-2,4}

  So there are 6 combinations. Now what does the cumumlative sum array says. See the following patters, 
  1) The 4th entry is 5. That means that's an array with sum 5. 
  2) 3rd entry is there. That Says 6. So if a submatrix occurs before 6 whose sum is 1, then that can will mean that there is submatrix with sum 5 and a submatrix with sum 1. 
  3) Similarily we can check for other entries. 
  This can be checked using a hashmap which uses time complexity of O(1).

  But I got stumbled upon how do I deal with 6 in my prefix sum. Then we have to use the second entry of our unordered map. We'll use it as a counter. 
  If 6 is occuring twice then we'll set the value associated with the key 6 to increment by 1. In fact we'll increment the values associated with all the keys by 1 everytime we encounter them. 
   
*/

#include <iostream> 
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> hashMap;
      int counter = 0;
      int prefixSum = 0;      
      hashMap[0] = 1;
        
      for(int i = 0;i < nums.size();i++) {
        prefixSum += nums[i];
        if(hashMap.find(prefixSum - k) != hashMap.end()) {
          counter += hashMap[prefixSum - k];
        }  
              
        hashMap[prefixSum]++;        
      } 
      cout<<"Final count = "<<counter<<endl;
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