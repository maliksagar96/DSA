#include <iostream> 
#include <vector> 

using namespace std;

class Solution{
  public:
   int search(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
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