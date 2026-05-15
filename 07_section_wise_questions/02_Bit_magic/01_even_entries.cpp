#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findEvenOccurrences(vector<int>& arr) {

      vector<int> answer;
      unordered_map<int, int> evenNums;

      for(int &x : arr) {
        evenNums[x]++;
      }

      for(int &x : arr) {
        if(evenNums[x] %2 == 0) {
          answer.push_back(x);
          evenNums[x] = -1;
        }
      }

      if(answer.size() == 0) return {-1};

      return answer;
        
    }
};

int main() {

  return 0;
}