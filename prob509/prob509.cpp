/*
  1) The space complexity increases in this code because of the depth of the call stack which is O(n).
  Time complexity is O(n).

  2) This code is using both recursion and memoisation.

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int fib(int n) {
      if(n<=1) {
        return n;
      }
      vector<int> fibonacci_sequence(n+1, -1); 

      fibonacci_sequence[0] = 0;
      fibonacci_sequence[1] = 1;

      return fib_memory(n, fibonacci_sequence);
    }

    int fib_memory(int n, vector<int>& fibonacci_sequence) {
      
      if(fibonacci_sequence[n] != -1) {
        return fibonacci_sequence[n];
      }
      else{
        fibonacci_sequence[n] = fib_memory(n-1, fibonacci_sequence) + fib_memory(n-2, fibonacci_sequence);
        return fibonacci_sequence[n];
      }
    }

};

int main() {
  Solution sol;

  sol.fib(2);
  // cout<<sol.fib(2)<<endl;
  return 0;
}