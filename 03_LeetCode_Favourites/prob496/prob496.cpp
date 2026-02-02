#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>


using namespace std;

class Solution {
  public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {      
      vector<int> result;
      stack<int> stk;

      stk.push(nums2[0]);
      unordered_map<int, int> stkmap;

      for(int i = 1;i<nums2.size();i++) {
              
        while(!stk.empty() && (stk.top() < nums2[i]))
        {

          stkmap[stk.top()] = nums2[i];
          stk.pop();
        } 
        
          stk.push(nums2[i]);
        
      }

      while (!stk.empty()) {
        stkmap[stk.top()] = -1;
        stk.pop();
      }

      for(int num:nums1) {
        result.push_back(stkmap[num]);
      }
      return result;


    }
};

int main() {

  Solution sol;

  vector<int> nums1 = {4,1,2};
  vector<int> nums2 = {1,3,4,2};

  vector<int> result =  sol.nextGreaterElement(nums1, nums2);

  for(int i = 0;i<result.size();i++) {

    cout<<result[i]<<endl;
  }
  

  return 0;
}