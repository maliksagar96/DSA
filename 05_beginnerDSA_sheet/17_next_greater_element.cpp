#include <iostream>
#include <vector>
#include <stack>

using namespace std;
/*
class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
			vector<int> ans;
			int n = arr.size();
			for(int i = 0;i<n-1;i++) {
				for(int j = i+1;j<n;j++) {
					if(arr[j] > arr[i]) {
						ans.push_back(arr[j]);
						break;
					}
				}
				if(ans.size() <= i) {
					ans.push_back(-1);
				}
			}
			ans.push_back(-1);
	
			return ans;
        
    }
};
*/

class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
			
			int n = arr.size();
			vector<int> ans(n, -1);
			stack<int> stk;

			for(int i = 0;i<n;i++) {
				while(!stk.empty() && arr[i] > arr[stk.top()]) {
			
					ans[stk.top()] =  arr[i];
					stk.pop();
					
				}
				stk.push(i);
			}
    
			return ans;
    }
};


int main() {

	Solution sol;
	vector<int> arr = {1, 3, 2, 4};

	vector<int> ans = sol.nextLargerElement(arr);

	for(int i = 0;i<ans.size();i++) 
		cout << ans[i] << "\t";

	cout<<endl;

    return 0;
}