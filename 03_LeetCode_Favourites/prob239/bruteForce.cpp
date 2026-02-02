#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> maxNums;	
		for(int i = 0;i<=nums.size()-k;i++) {
			int max1 = nums[i];
			for(int j = 1;j<k;j++) {
				if(max1 < nums[i+j]) max1 = nums[i+j];
			}
			maxNums.push_back(max1);		
		}
		return maxNums;
	}
};

int main() {

    return 0;
}