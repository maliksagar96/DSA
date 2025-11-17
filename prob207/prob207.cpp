#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>

using namespace std;

class Solution {
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<vector<int>> adj_list(numCourses);
    vector<int> indegree(numCourses, 0);

    // build adj_list
    for (auto &p : prerequisites) {
      int a = p[0], b = p[1];
      adj_list[b].push_back(a);
      indegree[a]++;
    }

    // print adj_list (adjacency list)
    cout << "adj_list adjacency list:" << endl;
    for (int i = 0; i < adj_list.size(); i++) {
      cout << i << " -> ";
      for (int v : adj_list[i]) {
        cout << v << " ";
      }
      cout << endl;
    }


    queue<int> q;
    for (int i = 0; i < numCourses; i++)
      if (indegree[i] == 0) q.push(i);

    // cout << "Initial queue (indegree 0):" << endl;
    // queue<int> temp = q; // make a copy
    // while (!temp.empty()) {
    //   cout << temp.front() << " ";
    //   temp.pop();
    // }
    // cout << endl;

		
    int count = 0;
    while (!q.empty()) {		
      int u = q.front();
      q.pop();
      count++;
      for (int v : adj_list[u]) {
        if (--indegree[v] == 0)
          q.push(v);
      }
    }

    return count == numCourses;
  }
};

int main() {
  Solution s;
  int numCourses = 6;
  vector<vector<int>> prerequisites = {
    {1, 0}, {2, 1}, {3, 2}, {4, 2}, {5, 3}, {5, 4}
  };

  cout << (s.canFinish(numCourses, prerequisites) ? "Possible" : "Not possible") << endl;
  return 0;
}
