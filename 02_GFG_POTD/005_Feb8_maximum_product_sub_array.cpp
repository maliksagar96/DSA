/*
    This seems like a greedy approach but this is a DP problem. 
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int global_max = arr[0];
        int min_yet = arr[0];
        int max_yet = arr[0];

        // for(int n : arr) {
        //     cout << n << "\t";
        // }

        cout <<endl;
        for(int i = 1;i<arr.size();i++) {
            int currNum = arr[i];
            int maxIntoCurrNum = currNum * max_yet;
            int minIntoCurrNum = currNum * min_yet;
            max_yet = max({arr[i], maxIntoCurrNum, minIntoCurrNum});
            min_yet = min({arr[i], maxIntoCurrNum, minIntoCurrNum});
            global_max = max(global_max, max_yet);
            // cout <<"**********************************\n";
            // cout << "i = "<<i<<endl;
            // cout << "max_yet = "<< max_yet << endl;
            // cout << "min_yet = "<< min_yet << endl;
            // cout << "global_max = "<< global_max <<endl;
        }


        return global_max;
        
    }
};

int main() {

    // vector<int> arr = {-2, 6, -3, -10, 0, 2};
    vector<int> arr = {-1, -3, -10, 0, 6};
    Solution sol;
    cout << "Maximum Product = "<< sol.maxProduct(arr)<<endl;

    return 0;
}
