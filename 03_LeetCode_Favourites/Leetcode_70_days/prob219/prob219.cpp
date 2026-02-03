#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool containsNearbyDuplicate(vector<int>& nums, int k) {
    int sz = nums.size();
    if(k == 0 || sz == 0 || sz == 1) return false;
    unordered_set<int> hashSet;
    hashSet.insert(nums[0]);
    for(int i = 1;i<sz;i++) {
      if(hashSet.count(nums[i]))
      {
        return true;
      }
        
      if(i>=k) hashSet.erase(nums[i - k]);
      hashSet.insert(nums[i]);
    }  

    return false;    
  }
};

int main() {

  Solution sol;

  vector<int> nums = {1,2,3,1,2,3};
  int k = 2;

 cout<< sol.containsNearbyDuplicate(nums, k)<<endl;

  return  0;
}