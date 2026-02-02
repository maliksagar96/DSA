/*
  Well the tricky part in this problem is that in the queue don't store the values but store the indices.
*/

#include <iostream>
#include <vector> 
#include <queue>

using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
      if(k == 1) return arr;
      
      vector<int> maxArray;
      deque<int> tempnums;      
      
      for(int i = 0; i < arr.size(); i++) {
        //Remove the top value which is out of window.
        if(!tempnums.empty() && tempnums.front() <= i-k)
          tempnums.pop_front();
        
        //pop from back which are smaller then the top
        while(!tempnums.empty() && arr[tempnums.back()] < arr[i]) 
          tempnums.pop_back();

        tempnums.push_back(i);

        if(i>=k-1) {
          maxArray.push_back(arr[tempnums.front()]);
        }
      }

      // for(int n : maxArray) {
      //   cout << n << endl;
      // }

      return maxArray;

    }
};

int main() {

  vector<int> nums = {1, 2, 3, 1, 4, 5, 2, 3, 6};
  int k = 3;

  Solution sol;
  sol.maxOfSubarrays(nums, k);

  return 0;

}