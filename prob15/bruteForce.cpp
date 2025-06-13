
/**

Evem the brute force problem for this is not that straightforward. 
Set is a new data type for me. So set will contain only the unique entries automatically. 

So if I insert a sorted 3 element vector<int> then it will take care of duplicate entries on its own. 
And that is what is done here.

In the last line vector<vector<int>>(unique_result.begin(), unique_result.end());
How eaxctly does this work, i think i will get it over time. 

**/


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