#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> map;
    
    map[nums[0]] = 0;

    for(int i = 1;i<nums.size();i++) {
      int diff = target - nums[i];
      //search the hasmap for target-nums[i]
      if(map.contains(diff)) {
        return {i, map[diff]};
      }
      map[nums[i]] = i;
    }
    return {};
    
  }
};


int main() {

  return 0;
}