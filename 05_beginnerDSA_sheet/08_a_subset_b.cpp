#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    // Function to check if b is a subset of a
    bool isSubset(vector<int> &a, vector<int> &b) {
        // Your code here
      unordered_map<int, int> frequency;

      for(int x:a) frequency[x]++;

      for(int x:b) {
        if(frequency[x] == 0) return false;
        frequency[x] --;
      }

      return true;

    }
};

int main() {

  

  return 0;
}