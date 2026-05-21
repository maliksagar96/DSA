#include <iostream> 
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    ranges::sort(nums);

    for(int i = 0;i<n-2;i++) {
      int left = i+1;
      int right = n-1;
      while(left < right) {
        int sum = nums[i] + nums[left] + nums[right];
        if(sum == 0) {
          result.push_back({nums[i], nums[left], nums[right]});
          left++;
          right--;
        }

        else if(sum > 0) {
          right--;
        }

        else {
          left++;
        }
      }
    }

    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());

    return result;

  }
};


int main() {


  return 0;
}