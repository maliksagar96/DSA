/*
  The following lies under the umbrella of "greedy" algorithms. 
  There is no backtracking here for modifying earlier choices.  
  This searches for local minimas and hope that we'll find a global minima in such a way. 

  This commit now and never look back is the hallmark of greedy algorithms. 

  This algorithm tracks the lowest price yet and sell it now if the yield is the largest yet. 

  So this algorithm basically says buy at every valley sell at every peak.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int maxProfit = 0;
        int minPrice = prices[0];

        for(int i = 1;i<prices.size();i++) {

          int profit = prices[i] - minPrice; 
          maxProfit = (maxProfit < profit) ? profit : maxProfit;
          minPrice = (minPrice < prices[i]) ? minPrice:prices[i];

        }

        if(maxProfit <= 0) {
          return 0;
        }

        return maxProfit;
        
    }
};

int main() {

  vector<int> prices = {7, 10, 1, 3, 6, 9, 2};
  // vector<int> prices = {7, 6, 4, 3, 1};
  // vector<int> prices = {1, 3, 6, 9, 11};

  Solution sol;
  cout << sol.maxProfit(prices) << endl;

  return 0;

}