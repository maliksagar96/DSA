#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> hashSet;
    
    hashSet.insert(nums[0]);

    for(int = 0;i<nums.size();i++) {
      if(hashSet.contains(nums[i])) 
        return true;
      hashSet.insert(nums[i]);
    }

    return false;
  }
};


int main() {

  return 0;
}