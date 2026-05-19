#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> fibonacciNumbers(int n) {
			// code here
			vector<int> fib(n, 0);
			fib[0] = 0;
			fib[1] = 1;

			for(int i = 2;i<n;i++) {
				fib[i] = fib[i-1] + fib[i-2];
			}

			return fib;

    }
};

int main() {

	return 0;
}