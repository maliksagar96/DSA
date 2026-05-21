#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
      int sz = nums.size();
      for(int i = 0; i < sz-1; i++){
        for(int j = i+1; j < sz; j++){
          if(nums[i] > nums[j]){
            swap(nums[i], nums[j]);
          }
        }
      }
    }
    void swap(int& a, int& b){
      int temp = a;
      a = b;
      b = temp;
    }
};


int main(){

  Solution sol;
  vector<int> nums = {2,0,2,1,1,0};
  sol.sortColors(nums);
  for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}