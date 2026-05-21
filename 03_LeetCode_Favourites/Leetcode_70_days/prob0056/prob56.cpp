#include <iostream>
#include <ranges>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		ranges::sort(intervals);
		vector<vector<int>> ans;
		
		for(int i = 0;i<intervals.size();i++) {
			if(ans.empty() || interval[i][0] > ans.back()[1]) {
				ans.push_back(interval[i]);
			}

			else {
				ans.back()[1] = max(ans.back()[1], intervals[i][1]);
			}
		}

		return ans;


		}
};


int main() {

    return 0;
}