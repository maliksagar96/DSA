#include <iostream> 
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      set<vector<int>> unique_result;
        vector<vector<int>> result;
      for(int i = 0;i<nums.size()-2;i++) {
        for(int j = i+1;j<nums.size() -1;j++) {
          for(int k = j+1;k<nums.size();k++) {
            if(nums[i] + nums[j] + nums[k] == 0) {
              vector<int> triplet = {nums[i], nums[j], nums[k]};
              sort(triplet.begin(), triplet.end());
              unique_result.insert(triplet);
            }
          }
        }
      }      
      return vector<vector<int>>(unique_result.begin(), unique_result.end());
    }
};

int main() {


  return 0;
}