#include <iostream>
#include <vector>
#include <algorithm>  // for reverse()

using namespace std;

class Solution {
  public:
    void rotate(vector<int> &arr, int m) {
        
        reverse(arr.begin(), arr.end());
        reverse(arr.begin()+m, arr.end());
        reverse(arr.begin(), arr.begin()+m);

        for(int i = 0;i<arr.size();i++) {          
          cout << arr[i] << endl;  
        }        
    }
};



int main() {

  Solution sol;

  vector<int> arr = {1,2,3,4,5,6};
  vector<int> arr2 = {0,0,0,4,5,6,0,0};
  

  sol.rotate(arr2, 2);

  return 0;
}