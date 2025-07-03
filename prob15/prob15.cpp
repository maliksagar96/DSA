#include <iostream> 
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    set<vector<int>> hashSet;
    sort(nums.begin(), nums.end());
    int sz = nums.size()-1;
    for(int i = 0; i < nums.size()-2; ++i) {      
      
      int left = i+1, right = sz;

      while(left < right) {
        int sum = nums[i] + nums[left] + nums[right];        
        if(sum == 0) {
          hashSet.insert({nums[i], nums[left], nums[right]});
          left++;right--;
        }        
        else if(sum > 0) {
          right--;
        }
        else{
          left++;
        }        
      }
    }
    return vector<vector<int>> (hashSet.begin(), hashSet.end());
  }
};


int main() {


  return 0;
}