#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
      int maxArea(vector<int>& height) {
        int area, maxar = 0;
        int ht = height[0];
        for(int i=0;i<height.size()-1;i++) {
          for(int j=i+1;j<height.size();j++) {
            ht = height[j];
            if(height[i] < height[j]) ht = height[i];
            area = ht * (j-i);
            if(area > maxar) maxar = area;
          }
        }      

        return maxar;
      }

  };

int main() {
  vector<int> height = {1,8,6,2,5,4,8,3,7};

  Solution sol;

  cout<<"Maxarea = "<<sol.maxArea(height)<<endl;

  return 0;
}