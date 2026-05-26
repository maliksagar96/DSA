class Solution {
  public:
    bool checkElements(int start, int end, vector<int> &arr) {
        // code here
			unordered_set<int> nums;
			int n = arr.size();
			for(int i = 0;i<n;i++) {
				nums.insert(arr[i]);
			}		

			for(int i = start;i<end;i++) {
				if(nums.find(i) == nums.end()) {
					return false;
				}
			}

			return true;
    }
};
