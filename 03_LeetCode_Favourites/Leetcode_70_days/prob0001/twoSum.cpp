#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> hashMap;
  
		for(int i = 0;i<nums.size();i++) {
			int needed = target - nums[i];
			if(hashMap.contains(needed)) {
				return {i, hashMap[needed]};
			}

			hashMap[nums[i]] = i;

		}
		return {};		
	}
};

int main() {


}