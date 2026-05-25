#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		
		unordered_set<int> hashSet(nums.begin(), nums.end());
		
		int longest = 0;

		for(int num:nums) {
			int length = 0;
			if(!hashSet.contains(num-1)) {
				int nextNum = num+1;
				length += 1;
				while(hashSet.contains(nextNum)) {
					nextNum += 1;
					length++;
				}

			}

			longest = max(longest, length);
		}
					
		return longest;
	}
};

int main() {

	Solution sol;
	vector<int> nums = {100,4,200,1,3,2};
	cout << sol.longestConsecutive(nums) << endl;

	return 0;

}

