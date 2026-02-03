#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> curr;
    vector<bool> used(nums.size(), false);
    backtrack(nums, curr, result, used);
    return result;   
  }

  void backtrack(vector<int>& nums, vector<int>& curr, vector<vector<int>>& result, vector<bool>& used) {
    if(nums.size() == curr.size()) {
      result.push_back(curr);
      return;
    }

    for(int i = 0;i<nums.size();i++) {
      if(used[i]) continue;
      used[i] = true;
      curr.push_back(nums[i]);
      backtrack(nums, curr, result, used);
      used[i] = false;
      curr.pop_back();
    }
  }

};

int main() {

  return 0;
}