#include <iostream>
#include <vector>

using namespace std;


// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        int bit_point = arr[0];
        for(int i = 1;i<arr.size();i++) {
          bit_point = bit_point > arr[i] ? bit_point : arr[i];
        }

        return bit_point;
        
    }
};

int main() {

  Solution sol;

  // vector<int> arr = {1, 2, 4, 5, 7, 8, 3};
  // vector<int> arr = {10, 20, 30, 40, 50};
  vector<int> arr = {120, 100, 80, 20, 0};

  cout << "Bitonic Point = " << sol.findMaximum(arr) << endl;

  return 0;
}