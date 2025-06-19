#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      for(int i = 0;i<numbers.size()-1;i++) {
        for(int j = i+1;j<numbers.size();j++) {
          if(numbers[i] + numbers[j] == target) {
            return vector<int>{i+1,j+1};
          }
        }
      }      
      return vector<int>{-1,-1};
    }
};

int main(){

  return 0;
}