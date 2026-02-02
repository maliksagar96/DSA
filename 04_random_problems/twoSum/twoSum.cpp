/*

Two sum is one of the most simple problems one can encounter. 
It just depends on if you know something like hashmap or not. 

*/

#include <iostream> 
#include <vector> 
#include <unordered_map>

using namespace std;

class Solution {
  public:
      vector<int> twoSum(vector<int>& nums, int target) {
          vector<int> result(2,0);
          
          unordered_map<int, int> map;
          map[nums[0]] = 0;
          for(int i = 1;i<nums.size();i++) {            
            if(map.find(target - nums[i]) != map.end()) {
              result[0] = i;
              result[1] = map[target - nums[i]];
            }
            map[nums[i]] = i;
          }

          return result;
      }
  };
  
int main() {

  return 0;
}