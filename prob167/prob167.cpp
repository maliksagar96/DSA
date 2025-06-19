#include <iostream>
#include <vector> 

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      int left = 0, right = numbers.size()-1;
      for(int i = 0;i<numbers.size();i++) {
        int sum = numbers[left] + numbers[right];
        if(sum == target) {
          return vector<int> {left+1, right+1};
        }
        else if(sum> target) {
          right--;
        }
        else{
          left++;
        }
      }      
      return vector<int>{-1,-1};
    }
};

int main(){

  return 0;
}