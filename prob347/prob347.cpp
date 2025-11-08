#include <iostream>

usign namespace std;

class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {    
    unordered_map<int, int> frequency;

    for(int n:nums) 
      frequency[n]++;
  }

  priority_queue< pain<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;

  for(auto &[num, freq]: frequency) {
    min_heap.push({freq, num});
    if(min_heap.size() > k)
      min_heap.pop();
  }

  vector<int> result;
  while(!min_heap.empty()) {
    result.push_back(min_heap.top().second);
    min_heap.pop();
  }

  return result;

};