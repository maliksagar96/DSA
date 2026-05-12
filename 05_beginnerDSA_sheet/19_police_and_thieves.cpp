#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
      // Code here

			int n = arr.size();

			vector<int> police;
			vector<int> thieves;

			for(int i = 0;i<n;i++) {
				if(arr[i] == 'P') police.push_back(i);
				else thieves.push_back(i);
			}
      
			int police_pntr = 0;
			int thieves_pntr = 0;

			int policeSize = police.size();
			int thievesSize = thieves.size();

			int counter = 0;
			while(police_pntr < policeSize && thieves_pntr < thievesSize) {
				if(abs(police[police_pntr] - thieves[thieves_pntr]) <= k) {
					counter++;
					police_pntr++;
					thieves_pntr++;
				}

				else if(thieves[thieves_pntr] > police[police_pntr]) {
					police_pntr++;
				}

				else {
					thieves_pntr++;
				}

			}
			

			return counter;
    }
};

int main() {

	Solution sol;

	vector<char> arr = {'P', 'T', 'T', 'P', 'T'};

	sol.catchThieves(arr, 0);

	return 0;
}