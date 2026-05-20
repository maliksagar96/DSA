#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void sortHalves(int arr[], int n) {
			// your code here
			vector<int> sortedArr;
			int breakPoint = 0, right;
			int left = 0;			

			while((breakPoint + 1) < n && arr[breakPoint] <= arr[breakPoint+1]) {				
				breakPoint++;
			}
      
			right = breakPoint + 1;						
			// cout << right <<endl;
	
			while(left <= breakPoint && right < n) {
				if(arr[left] <= arr[right]) {
					sortedArr.push_back(arr[left++]);
				}

				else {
					sortedArr.push_back(arr[right++]);
				}				
			}

			while(left <= breakPoint) {
				sortedArr.push_back(arr[left++]);
			}

			while(right < n) {
				sortedArr.push_back(arr[right++]);
			}

			for(int i = 0;i<n;i++) {
				arr[i] = sortedArr[i];
				// cout << arr[i] << endl;
			}

    }
};

int main() {

	Solution sol;
	vector<int> arr = {2,3,8,-1,7,10};
	sol.sortHalves(arr.data(), arr.size());

	return 0;
}