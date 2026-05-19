/*
	This code is correct but the space complexity is still O(n).
	Since the number is getting doubled everytime, this can be given as a pattern infact. 
*/

#include <iostream>
#include <vector>

using namespace std;

// class Solution {
//   public:
//     int minOperation(int n) {
// 			// code here.
// 			vector<int> operations(n+1);

// 			operations[0] = 0;
// 			operations[1] = 1;
// 			operations[2] = 2;

// 			for(int i = 3;i<n+1;i++) {
// 				if(i%2 == 0)
// 					operations[i] = min(operations[i-1] + 1, operations[i/2] + 1);	
// 				else 
// 					operations[i] = min(operations[i-1] + 1, operations[i/2] + 2);	
// 			}

// 			return operations.back();

//     }
// };

class Solution {
  public:
    int minOperation(int n) {
			// code here.
			int operations = 0;						

			while(n > 0) {
				if(n%2 == 0) 
					n = n/2;
				else 
					n--;

				operations++;
			}

			return operations;
    }
};


int main() {

	return 0;
}