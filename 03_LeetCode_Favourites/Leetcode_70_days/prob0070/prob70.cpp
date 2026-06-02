/*

This is my first DP problem. 
What DP asks a user to do is to break down a problem into subproblems and then use the solutions to the subproblems to solve the main problem. 
Let see what is happening in this problem. 


What is happening is that you are at a current step and you either would take 1 step from there or 2 steps. 
And you would memorize the number of ways to reach the current step. And then you would use that to calculate the number of ways to reach the next step. 
Break the for loop in your mind to visualize it. 

*/


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

  int climbStairs(int n) {
    if(n <=2) return n;
    
    vector<int> ways(n+1, 0);

    ways[0] = 0;
    ways[1] = 1;
    ways[2] = 2;

    for(int i = 3;i<=n;i++) {
      ways[i] = ways[i-1] + 1;
    }

    return ways[n];
  }
};

int main() {
  Solution sol;
  int n = 4;
  cout << sol.climbStairs(n) << endl;
  return 0;
}
