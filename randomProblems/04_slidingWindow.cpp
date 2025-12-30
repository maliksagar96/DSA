#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> nums = {2, -1, 5, -3, 6, 2, -4, 3, 1};

  int windowSize = 3;
  int maxSum = 0;

  for(int i = 0;i<windowSize;i++) {
    maxSum += nums[i];
  }

  int currSum = maxSum;

  for(int i = windowSize;i<nums.size();i++) {
    int left = i-windowSize;
    int right = i;
    currSum += nums[right] - nums[left];

    if(currSum > maxSum) maxSum = currSum;
  }

  cout<<"Maxsum = "<<maxSum<<endl;

  return 0;
}