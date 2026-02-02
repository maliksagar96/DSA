/*
  Well we saw the backtrack in the subsets 1 problem. 
  This code is just 1 trick away from removing the duplicates. 
  Sort and then check if the previous num is same or not?

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> result;

  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    
    vector<int> subset;    
    backtrack(0, nums, subset);
    return result;
  }

  void backtrack(int start, vector<int>& nums, vector<int>& subset) {
    result.push_back(subset);      

    for(int i = start;i<nums.size();i++) {
      if(i > start && nums[i] == nums[i-1]) continue;
      subset.push_back(nums[i]);
      backtrack(i+1, nums, result, subset);
      subset.pop_back();
    }

  }

};


int main() {
  Solution s;
  vector<int> nums = {1, 2, 2};
  vector<vector<int>> res = s.subsetsWithDup(nums);

  for (auto &subset : res) {
    cout << "{ ";
    for (auto x : subset) cout << x << " ";
    cout << "}\n";
  }

  return 0;
}