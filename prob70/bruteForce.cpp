/*

This is a classic recursive problem. I find even the brute Force function is not that straightforward to grasp. 

So what is happening is that you are at a current step and you either would take 1 step from there or 2 steps. 

Now this would be solved recursively. 

You want 2 recursions at once. 

You take your first step as either 1 or 2 and then check. Then in both the subcases you take 1 step or 2 and then check -> 4 checks. And similarily you go on. Then 8 checks and so on. 

*/


#include <iostream>

using namespace std;

class Solution {
public:
  int climb(int currentStep, int n) {
    if (currentStep == n) return 1;
    if (currentStep > n) return 0;

    return climb(currentStep + 1, n) + climb(currentStep + 2, n);
  }

  int climbStairs(int n) {
    return climb(0, n);
  }
};

int main() {
  Solution sol;
  int n = 4;
  cout << sol.climbStairs(n) << endl;
  return 0;
}
