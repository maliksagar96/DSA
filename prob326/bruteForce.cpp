#include <iostream>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        int remainder;
        while(n > 1) {
            remainder = n % 3;
            if(remainder != 0) {
                return false;
            }
            n = n / 3;
        }

        return true;
    }
};

int main() {

    Solution sol;

    cout<<sol.isPowerOfThree(27)<<endl;
}