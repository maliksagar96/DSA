#include <iostream> 
#include <vector> 
using namespace std;

class Solution {
  public:
      vector<int> twoSum(vector<int>& nums, int target) {
          vector<int> result;
          const int OFFSET = 1000;
          cont int negativeLim = -1*OFFSET-1;
          vector<int> hashMap(2*OFFSET+1, negativeLim); 
          
          hashMap[nums[0]+OFFSET] = 0;
          for(int i = 1; i < nums.size(); i++) {
            int x = nums[i];               
            if(hashMap[target-x+OFFSET] != negativeLim) {
              result.push_back(i);
              result.push_back(hashMap[target-x+OFFSET]);
              return result;
            }
            hashMap[nums[i] + OFFSET] = i;
          }
          cout << "There are no solutions" << endl;
          return result;
      }
  };
  


int main() {

  return 0;
}