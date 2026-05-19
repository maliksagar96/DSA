
class Solution {
  public:
    void sortHalves(int arr[], int n) {
			// your code here
			int n = arr.size()-1;
			int left = 0;
			int right = n;

			while(arr[left] < arr[left+1] && (left + 1) < n) {				
				left++;
			}
      
			right = left;
			left = 0;

    }
};