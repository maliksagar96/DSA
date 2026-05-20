/*
classic binary search.

*/

#include <iostream> 
#include <vector> 

using namespace std;

class Solution{
  public:
   int search(vector<int>& nums, int target) {

    if(nums.size() == 1) {
      if(nums[0] == target) return 0;
      else return -1; 
    }

    int low = 0, high = nums.size();
    int mid = low + (high-low)/2;
    
    while(low <= high) {
      if(nums[mid] == target) {        
        return mid;
      }

      else if(nums[mid] < target) {
        low = mid+1;
      }

      else {
        high = mid-1;
      }

      mid = low + (high - low)/2;
    }

    return -1;
}

};

int main() {

  // vector<int> nums = {-1,0,3,5,9,12};
  vector<int> nums = {5};


  Solution sol;
  // sol.search(nums, 2);

  cout<<"The index = "<<sol.search(nums, 5)<<endl;

  return 0;

} 