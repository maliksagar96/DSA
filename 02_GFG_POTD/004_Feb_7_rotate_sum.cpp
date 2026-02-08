#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        int n = arr.size();
        int totalSum = 0;
        int weightedSum = 0;
        
        for(int i = 0;i<n;i++) {
            totalSum += arr[i];
            weightedSum += i * arr[i];
        }

        int maxSum = weightedSum;
    
        for(int i = 1;i<n;i++) {
            int currNum = arr[n-i];
            weightedSum = weightedSum + totalSum - n*currNum;
            // cout << "currNum = "<<currNum<<", currSum = "<<weightedSum << endl;
            maxSum = maxSum > weightedSum ? maxSum : weightedSum;
        }

        // cout <<endl;
        return maxSum;
    }
};

int main() {
    vector<int> arr = {3, 1, 2, 8};

    Solution sol;

    cout << "Max sum = "<< sol.maxSum(arr) << endl;

    return 0;
}