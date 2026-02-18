#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void rotate(vector<int> &arr) {
        // code here
        int last = arr.back();

        int n = arr.size();

        for(int i = 1; i < arr.size();i++) {
          arr[n - i] = arr[n-i-1];
        }
        arr[0] = last;        
    }
};



int main() {

  return 0;
}