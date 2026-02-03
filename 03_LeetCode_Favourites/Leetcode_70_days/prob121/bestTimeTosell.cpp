/*
  Actually when you come to think about it, it is very easy to keep track of the maximum 
  and minimum elements of an array in a single pass. 
  
  That is what we are doing here. Keeping track of min and max in a single pass. If the current entry is the smallest then 
  there would be no profit. This entry will be saved a mininmum. If the next elements are bigger then this 
  then we would have first case of profit. 
  The key would then become to maximize this profit. 
*/

#include <iostream> 
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int max, min, profit;
      max = 0;
      profit = 0;
      min = prices[0];      
      for(int i = 0;i<prices.size();i++) {
        if(min > prices[i]) min = prices[i];
        profit = prices[i] - min;
        if(max < profit) max = profit;
      }
      return max;
    }
  };

int main() {
  Solution sol;
  vector<int> prices = {1,2};
  cout<<"Max profit = "<<sol.maxProfit(prices)<<endl;
  return 0;
}