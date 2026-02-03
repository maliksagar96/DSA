/*
	This one is tough. Ooh lala. 
	A good way to understand this is by making a call stack diagram. 
	Use the example [1,2,3] and then asses each step and see what the call stack will hold and then resolve the call stack step by step. 
*/

/*
	This is a dfs problem. We'll search the tree depth first and then while retracing our steps backwards we backtrack the changes we did. 
	This makes it tricky. 
	The following solution is a brute force solution and it happens to be the optimal solution!!
*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> curr;

    void backtrack(vector<int>& nums, int start) {
        res.push_back(curr);
        for (int i = start; i < nums.size(); ++i) {
            curr.push_back(nums[i]);
			// for(int j = 0;j<curr.size();j++) cout<<"curr["<<j<<"] = "<<curr[j]<<endl;
            backtrack(nums, i + 1);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(nums, 0);
        return res;
    }
};


int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> result = sol.subsets(nums);
    
    cout << "All subsets:\n";
    for (auto& subset : result) {
        cout << "[ ";
        for (auto& x : subset)
            cout << x << " ";
        cout << "]\n";
    }

    return 0;
}
