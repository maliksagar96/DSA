#include <iostream>
#include <vector>

using namespace std;
/************************BRUTE FORCE ************************/
// class Solution {
//   public:
//     int maxProfit(vector<int> &prices) {
//         int maxProfit = 0;

//         for(int i = 0;i<prices.size()-1;i++) {
//           int oldprice = prices[i];
//           for(int j = i+1;j<prices.size()-1;j++) {
//             int profit = prices[j] - oldprice;
//             maxProfit = (maxProfit > profit) ? maxProfit : profit;
//           }
//         }

//         if(maxProfit <= 0) {
//           return 0;
//         }

//         return maxProfit;
        
//     }
// };

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