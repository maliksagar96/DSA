#include <iostream>
#include <vector>


using namespace std;

class Solution {
  public:
    int findMin(int n) {
    // code here
			int count = 0;
			vector<int> currency = {10,5,2,1};

			int tens = n/10;
			n = n-tens*10;
			int fives = (n)/5;
			n = n-fives*5;
			int twos = (n/2);
			n = n-twos*2;
			int ones = n;
			return (tens + fives + twos + ones);
    }
};