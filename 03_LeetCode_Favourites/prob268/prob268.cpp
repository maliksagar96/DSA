#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
      int n = nums.size();
      int expected_sum = n * (n+1)/2;
      int sum = 0;
      for(int i = 0;i<n;i++) {
        sum += nums[i];
      }
      return (expected_sum - sum);
    }
};

int main() {

  vector<int> nums = {3,0,1};
  Solution sol;

  cout << sol.missingNumber(nums) << endl;


  return 0;
}
