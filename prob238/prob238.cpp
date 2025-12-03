#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> productExceptSelf(vector<int>& nums) {
    int sz = nums.size();
    if(sz == 0 || sz == 1) return {};

    vector<int> result;
    
    int preFix = 1;
    for(int i = 0;i<sz;i++) {
      result.push_back(preFix);
      preFix *= nums[i];
    } 

    int postFix = 1;
    
    for(int i = sz-1; i>= 0;i--) {      
      result[i] *= postFix;
      postFix *= nums[i] 
      
    }

    

    return result;
  }
};

int main() {

  return 0;
}