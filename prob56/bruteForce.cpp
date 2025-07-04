#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isOverlap(const vector<int>& a, const vector<int>& b) {
        return !(a[1] < b[0] || b[1] < a[0]);
    }

    vector<int> mergeTwo(const vector<int>& a, const vector<int>& b) {
        return {min(a[0], b[0]), max(a[1], b[1])};
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<bool> merged(n, false);
        
        for (int i = 0; i < n; ++i) {
            if (merged[i]) continue;
            for (int j = i + 1; j < n; ++j) {
                if (merged[j]) continue;
                if (isOverlap(intervals[i], intervals[j])) {
                    intervals[i] = mergeTwo(intervals[i], intervals[j]);
                    merged[j] = true;
                    // Restart inner loop to check new merged interval
                    j = i;
                }
            }
        }

        vector<vector<int>> result;
        for (int i = 0; i < n; ++i) {
            if (!merged[i]) {
                result.push_back(intervals[i]);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> interval = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution sol;
    vector<vector<int>> merged = sol.merge(interval);

    for (auto& v : merged) {
        cout << "[" << v[0] << ", " << v[1] << "]" << endl;
    }

    return 0;
}
