#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
  public:
	
		struct item{
			double ratio;
			int val;
			int weight;
		};


    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
			int n = val.size();
			vector<item> items(n);

			for(int i= 0;i<n;i++) {
				items[i].val = val[i];
				items[i].weight = wt[i];
				items[i].ratio = (double)val[i]/wt[i];
			}

			sort(items.begin(), items.end(), [](const item& a, const item& b){ return a.ratio > b.ratio;});
			
			double totalVal = 0;
			for(int i = 0;i<n;i++) {

				if(capacity > items[i].weight) {
					totalVal += items[i].val;
					capacity -= items[i].weight;
				}

				else {
					totalVal += capacity * items[i].ratio;
					break;
				}

			}

			return totalVal;

    }
};



int main() {

    return 0;
}