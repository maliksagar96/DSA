#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
  long long findCost(const vector<int>& heights,
                     const vector<int>& cost,
                     int targetHeight) {
    long long currCost = 0;   // ❌ was int → can overflow
    for (int i = 0; i < heights.size(); i++) {
      currCost += 1LL * abs(heights[i] - targetHeight) * cost[i];
    }
    return currCost;
  }

  int minCost(vector<int>& heights, vector<int>& cost) {

    // ❌ Earlier code binary-searched on index (wrong domain)
    // ✅ We must binary-search on HEIGHT values (answer space)

    int left = *min_element(heights.begin(), heights.end());
    int right = *max_element(heights.begin(), heights.end());

    while (left < right) {
      int mid = left + (right - left) / 2;

      long long costMid = findCost(heights, cost, mid);
      long long costMidNext = findCost(heights, cost, mid + 1);

      if (costMid <= costMidNext) {
        right = mid;      // move left
      } else {
        left = mid + 1;   // ❌ earlier you had mid-1 (wrong, breaks BS)
      }
    }

    return findCost(heights, cost, left);
  }
};

int main() {
  vector<int> heights = {7, 1, 5};
  vector<int> cost = {1, 1, 1};

  Solution sol;
  cout << "Min cost = " << sol.minCost(heights, cost) << endl;
}
