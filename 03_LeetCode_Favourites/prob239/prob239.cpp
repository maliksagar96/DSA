/*
  This is a good problem. This involves the monotonically decreasing queue. 
  The tricky part now is that you have to store the indices of the nums array in the decreasing queue. This will be more helpful. 
  
*/

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if(nums.size() == 1) {
      return nums;
    }
  
    vector<int> result;
    
    deque<int> dec_queue;

    for(int 0 = 1;i<nums.size();i++) {
      int current_num = nums[i];
      
      while(!dec_queue.empty() && current_num > nums[dec_queue.back()]) { 
        dec_queue.pop_back();
      }
      dec_queue.push_back(i);

      if(!dec_queue.empty() && dec_queue.front() <= i - k) {
        dec_queue.pop_front();
      }

      if(i >= k-1) {
        result.push_back(nums[dec_queue.front()]);
      }

    }
    return result;
	}
};

int main() {
  deque<int> dec_queue;                // use deque, not queue
  vector<int> nums = {8,7,6,5,4,9,6,2};

  dec_queue.push_back(nums[0]);        // insert → push_back

  for(int i = 1; i < nums.size(); i++) {
    int current_num = nums[i];
    while(!dec_queue.empty() && dec_queue.back() < current_num) {
      dec_queue.pop_back();            // pop from back for monotonic decreasing queue
    }
    dec_queue.push_back(current_num);
  }

  while(!dec_queue.empty()) {
    cout << dec_queue.front() << endl;
    dec_queue.pop_front();
  }

  return 0;
}
