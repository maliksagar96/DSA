// User function Template for C++
#include <iostream>

using namespace std;

class Solution {
  public:
    int minStep(int H, int U, int D) {
			int h = 0;
			int counter = 0;
			while(1) {
				h = h + U;
				counter++;
				if(h>H) {
					return counter;	
					break;
				}
				h -= D;
			}

			return counter;
			
    }
};

class Solution {
  public:
    int minStep(int H, int U, int D) {
			if(U >= H) 
			return 1;


			return ((H - U + (U - D) - 1)/(U-D)) + 1;
			
    }
};



int main() {

	return 0;
}