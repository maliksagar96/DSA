#include <iostream>
#include <vector>
#include <climits>

using namespace std;

/*This is the way to make a sum using minimum number of coins. Suppose we want to make 4 using {1,2,3} the minimum number of coins is 4.*/

// class Solution {
//   public:
//     int count(vector<int>& coins, int sum) {
//         vector<int> ways(sum+1, INT_MAX);
//         //0 ways to count 0.
//         ways[0] = 0;
//         for(int target = 1;target<=sum;target++) {
//           for(int coin:coins) {
//             //We have to use a smaller coin then the target. target-coin should exist.
//             if(target-coin >=0 && ways[target - coin] != INT_MAX) {
//               ways[target] = min(ways[target], 1 + ways[target - coin]);              
//             }            
//           }
//         }    
//        return ways[sum];
//     }
// };

//Total ways to count
class Solution {
  public:
    int count(vector<int>& coins, int sum) {
        vector<int> ways(sum+1, 0);
        //1 ways to count 0. Chose no coin. Actually this is forcibly kept 0 because the way the algorithm is desiged later on. 
        ways[0] = 1;

        for(int coin:coins) {
          for(int target = coin;target<=sum;target++) {
            ways[target] += ways[target-coin];            
          }
        }
        
    return ways[sum];
       
    }
};

int main() {

  vector<int> coins1 = {2,3,4};
  int sum1 = 4;

  // vector<int> coins2 = {1, 2, 3};
  // int sum2 = 4;

  Solution sol;
  // sol.count(coins1, sum1);
  cout << "Targeted Sum = "<<sum1<<", Coins Required = "<< sol.count(coins1, sum1) << endl;



  return 0;
}