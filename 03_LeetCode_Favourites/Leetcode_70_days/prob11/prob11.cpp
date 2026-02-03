#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxArea(vector<int>& height) {
      int maxArea=0, area = 0;
      int left = 0;
      int right = height.size()-1;
      int ht = height[left];

      if(height[left] > height[right]) ht = height[right];
      area = ht * (right-left);
      while(right>left) {
        area = ht * (right-left);
      }
      
      return maxArea;
    }
};

int main() {
  vector<int> height = {1,8,6,2,5,4,8,3,7};

  Solution sol;

  cout<<"Maxarea = "<<sol.maxArea(height)<<endl;

  return 0;
}