/*
	These backtracking problems contain a pattern. See this problem and the problem 78. 
	These are good problems. 
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> res;
	vector<int> curr;

	void backtrack(vector<int>& nums, int target, int start) {
		if (target == 0) {
		res.push_back(curr);
			return;
		}
		if (target < 0) return;

		for (int i = start; i < nums.size(); ++i) {
			curr.push_back(nums[i]);
			backtrack(nums, target - nums[i], i); // reuse same number
			curr.pop_back(); // backtrack
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		backtrack(candidates, target, 0);
		return res;
	}
};

int main() {
	Solution sol;
	vector<int> candidates = {2, 3, 6, 7};
	int target = 7;

	vector<vector<int>> result = sol.combinationSum(candidates, target);
	for (auto& comb : result) {
		cout << "[ ";
		for (int n : comb) cout << n << " ";
		cout << "]\n";
	}
	return 0;
}
