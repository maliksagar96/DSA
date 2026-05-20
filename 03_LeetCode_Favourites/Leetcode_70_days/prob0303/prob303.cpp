/*
	
	If a function sumRange will be called again and again then it is optimal to calculate the prefix sum. 

*/

class NumArray {
    vector<int> prefix_sum;

    public:
    NumArray(vector<int>& nums) {
			int n = nums.size();
			prefix_sum.resize(n+1, 0);
			prefix_sum[0] = 0;
			for(int i = 0;i<n;i++) {
				prefix_sum[i + 1] = prefix_sum[i] + nums[i];
      }
    }
    
    int sumRange(int left, int right) {
        return (prefix_sum[right + 1] - prefix_sum[left]);
    }
};
