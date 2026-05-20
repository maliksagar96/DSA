

class Solution {
  public:
    int maxProduct(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int prod = arr[0] * arr[1];
        for(int i = 0;i<n-1;i++) {
            prod = max(prod, arr[i] * arr[i+1]);
        }
        
        return prod;
        
    }
};