#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
      
      int lowptr = 0;
      int midptr = 0;
      int highptr = nums.size()-1;
    
      while(midptr <= highptr) {
        if(nums[midptr] == 2) {
          swap(nums[midptr], nums[highptr]);
          highptr--;                
        }

        else if(nums[midptr] == 1){          
          midptr++;        
        }

        else {
          swap(nums[midptr], nums[lowptr]);
          lowptr++;
          midptr++;
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
  // vector<int> nums = {2,0,2,1,1,0};
  vector<int> nums = {1,0,2};
  sol.sortColors(nums);
  for(int i = 0; i < nums.size(); i++){
    cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}
