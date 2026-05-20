#include <iostream>
#include <vector>
#include <ranges>
#include <algorithm>

using namespace std;

class Solution {
  public:
    int minDiff(vector<int>& arr) {        
			// ranges::sort(arr);
			sort(arr.begin(), arr.end());
			int n = arr.size();
			int ans = abs(arr[1] - arr[0]);

			for(int i = 0;i<n-1;i++) {
				ans = min(ans, abs(arr[i] - arr[i+1]));
			}

			return ans;


    }
};

int main() {



	return 0;
}
