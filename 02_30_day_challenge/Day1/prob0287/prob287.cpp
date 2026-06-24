#include <vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
	
		int n = nums.size();
		vector<int> freq(n, 0);
		int ans;

		for(int i = 0;i<nums.size();i++) {
			if(freq[nums[i]] == 1) {
				return nums[i];
			}

			else{
				nums[i]++;
			}
		}
		return 0;
	}
};