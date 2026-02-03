/*
  The trick is nothing but to find the min and max index using 2 different binary searches. 
  There would be 2 loops. One for max and one for min. 
  In the min loop, keep shifting the high towards left. 
  In the max loop keep shifting the low towards right. 
  And that's it.

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
      vector<int> minMax(2,-1);
      int high = nums.size()-1, low = 0;
      
      //Binary Search for min
      while(high>=low) {
        int mid = low + (high-low)/2;
        if(nums[mid] == target) {
          minMax[0] = mid;          
          //move high to go left
          high = mid - 1;
        }
        else if(nums[mid] < target) low = mid + 1;
        else if(nums[mid] > target) high = mid - 1;
      }

      high = nums.size()-1, low = 0;
      
      //Binary search for max
      while(high>=low) {
        int mid = low + (high-low)/2;
        if(nums[mid] == target) {
          minMax[1] = mid;         
          //move low to go right.
          low = mid + 1;
        } 
        else if(nums[mid] < target) low = mid + 1;
        else if(nums[mid] > target) high = mid - 1;
      }

      return minMax;
    }
};

int main() {

  vector<int> nums = {5,7,7,8,8,10};
  vector<int> minMax(2,0);
  Solution sol;
  
  minMax = sol.searchRange(nums, 8);
  cout<<"Min = "<<minMax[0]<<endl;
  cout<<"Max = "<<minMax[1]<<endl;

  return 0;
}