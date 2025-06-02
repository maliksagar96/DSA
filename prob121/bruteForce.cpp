/*
  Brute force for this is also pretty easy. 
*/

#include <iostream> 
#include <vector>

using namespace std;

class Solution {
  public:
    int maxProfit(vector<int>& prices) {
      int max = 0;
      for(int i = 0;i<prices.size()-1;i++) {
        for(int j = i+1;j<prices.size();j++) {
          if(max < prices[j] - prices[i]) max = prices[j] - prices[i];
        }
      }
      return max;
    }
  };

int main() {

  return 0;
}