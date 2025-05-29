/*

  After first and second problem. This is very good problem. 
  It tells the user how to iterate through a hashmap.
  Simple but useful. 

  Here is the problem statement:
  ---
  **Problem: Majority Element**
  Given an array `nums` of size `n`, find the **majority element** — the element that appears **more than ⌊n / 2⌋ times**.
  You may assume that the majority element **always exists** in the array.
  ---
  **Example:**
  Input: `nums = [3, 2, 3]`
  Output: `3`
  Input: `nums = [2, 2, 1, 1, 1, 2, 2]`
  Output: `2`
  ---
*/

#include <iostream> 
#include <unordered_map> 
#include <vector>

using namespace std;

int maj(vector<int>& nums) {

  unordered_map<int, int> hashMap;
  for(int i:nums) {
    hashMap[i]++;
  }

  unordered_map<int, int>:: iterator it = hashMap.begin();
  int maxFreq = it->second;
  int maxElement = it->first;

  for(auto& pair:hashMap) {
    if(maxFreq < pair.second) {
      maxFreq = pair.second;
      maxElement = pair.first;
    }
  }
  
  cout<<"Max element = "<<maxElement<<", with maxFrequency of maxFreq = "<<maxFreq<<endl;
  return maxElement;
}

int main() {

  vector<int> nums = {3,2,3};
  maj(nums);
  return 0;
  
}