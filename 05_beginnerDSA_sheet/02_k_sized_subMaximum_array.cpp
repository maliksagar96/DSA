#include <iostream>
#include <vector>
#include <deque> 

using namespace std;

class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
      if(k == 1) return arr;

      vector<int> maxArray;
      deque<int> maxQueue;

      for(int i = 0;i<arr.size();i++) {

        if(!maxQueue.empty() && (maxQueue.front() <= (i-k))) 
          maxQueue.pop_front();
        
        while(!maxQueue.empty() && arr[maxQueue.back()] < arr[i]) 
          maxQueue.pop_back();
        
        maxQueue.push_back(i);

        if(i>=k-1) {
          maxArray.push_back(arr[maxQueue.front()]);
        }

      }
      return maxArray;

    }
};



int main() {

  vector<int> arr1 = {1, 2, 3, 1, 4, 5, 2, 3, 6};
  vector<int> arr2 = {5, 1, 3, 4, 2};
  int k1 = 3;
  int k2 = 1;

  Solution sol;
  vector<int> result1 = sol.maxOfSubarrays(arr1, k1);
  vector<int> result2 = sol.maxOfSubarrays(arr2, k2);

  for(int n:result1) {
    cout<<n<<"\t";
  }
  cout<<endl;

  for(int n:result2) {
    cout<<n<<"\t";
  }
  cout<<endl;

  return 0;
}