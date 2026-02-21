#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    long long sumMatrix(long long n, long long q) {
        // code here
        if(q < 2 || q > 2*n) return 0;
        else if(q <= n+1) return (q-1);
        else return (2*n-q+1);
        
    }
};

int main() {

    Solution sol;
    cout << sol.sumMatrix(4, 7) << endl;
    cout << sol.sumMatrix(5, 4) << endl;
}