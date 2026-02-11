#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
                
        for(int i = 1;i<arr.size();i++) {
          if(arr[i-1] > arr[i])           
          return i;          
        }

        return 0;

    }
};


int main() {

  vector<int> arr = {5, 1, 2, 3, 4};

  Solution sol;

  cout << "Value of k = "<<sol.findKRotation(arr) << endl;

  return 0;
}