#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int lis(vector<int>& arr) {
			// code here
			vector<int> ans;
			int n = arr.size();
			for(int i= 0;i<n;i++) {
				int num = arr[i];

				if(ans.size() == 0 || num > ans.back()) {
					ans.push_back(num);
				}		

				else {
					//repalce the last element which is > arr[i]
					int index = lower_bound(ans.begin(), ans.end(), num) - ans.begin();
					ans[index] = num;
				}
			}

			return ans.size();
    }
};

int main() {

	vector<int> ans = {12,2,3,4};

	// cout << ans.begin() << endl;
	// cout << ans.end() << endl;
	
	return 0;

}