#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        int sz = arr.size();
        vector<int> duplicates;

        vector<int> frequency(sz, 0);

        for(int i = 0;i<sz;i++) {
          frequency[arr[i]]++;
        }

        for(int i = 0;i<frequency.size();i++) {
          if(frequency[i] == 2) duplicates.push_back(i);
        }

        for(int i = 0;i<duplicates.size();i++) {
          cout << duplicates[i] << endl;
        }

        return duplicates;

    }
};

int main() {

  // vector<int> arr = {1,2,6,1,5,6,7};

  vector<int> arr = {1, 2, 3, 4, 5, 6, 8};

  Solution sol;
  sol.findDuplicates(arr);

  


  return 0;
}