#include <vector>

using namespace std;

class Solution {
public:
	int findDuplicate(vector<int>& nums) {
	
		vector<int> freq(1e5, 0);
		int ans;

		for(int i = 0;i<nums.size();i++) {
			if(freq[nums[i]] == 0) {
				freq[nums[i]++];
			}

			else{
				return nums[i];
			}
		}
		return 0;
	}
};