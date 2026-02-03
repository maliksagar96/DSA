#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      priority_queue<int, vector<int>, greater<int>> minheap; //defining minheap. 

      for(int n:nums) {
        minheap.push(n);
        if(minheap.size() > k) 
          minheap.pop();
      }

      return minheap.top();
    }
};

int main () {

  return 0;
}