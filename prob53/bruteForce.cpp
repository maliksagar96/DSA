#include <iostream> 
#include <vector> 
#include <climits> // for INT_MIN

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN;  // Use INT_MIN to handle negative numbers
        
        for(int windowSize = 1; windowSize <= (int)nums.size(); windowSize++) {        
            int end_window_index = nums.size() - windowSize;
            for(int window_index = 0; window_index <= end_window_index; window_index++ ) {
                int sum = 0;
                for(int i = window_index; i < window_index + windowSize; i++) {
                    sum += nums[i]; 
                }
                if(maxSum < sum) maxSum = sum;
            }
        }

        return maxSum;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    cout << "Max SubArray Sum: " << sol.maxSubArray(nums) << endl;
    return 0;
}
