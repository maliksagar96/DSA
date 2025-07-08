#include <iostream>
#include <vector>

using namespace std;

class Solution {  
  public:

  int robHouse(vector<int>& nums, int currentHouse) {
    int totalHouses = nums.size()-1;
    if(currentHouse == totalHouses) return nums[totalHouses];
    if(currentHouse > totalHouses)  return nums[totalHouses-1];
  }

  int rob(vector<int>& nums) {
    return robHouse(nums, 0);
  }
};

int main() {
  Solution sol;
  vector<int> nums = {1,2,3,1};
  cout << sol.rob(nums) << endl;
  return 0;
}
