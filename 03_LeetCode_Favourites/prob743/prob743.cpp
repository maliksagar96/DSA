#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int n, int k) {
    // Graph adjacency list: node -> list of (neighbor, weight)
    vector<vector<pair<int,int>>> adj_list(n + 1);
    for(auto &t : times){
      adj_list[t[0]].push_back({t[1], t[2]});
    }

    // Min-heap for Dijkstra: (distance, node)
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    pq.push({0, k});

    vector<int> dist(n + 1, INT_MAX);
    dist[k] = 0;

    while(!pq.empty()){
      auto [d, node] = pq.top(); pq.pop();
      if(d > dist[node]) continue; // Skip outdated entry

      for(auto &[nei, w] : adj_list[node]){
        if(dist[node] + w < dist[nei]){
          dist[nei] = dist[node] + w;
          pq.push({dist[nei], nei});
        }
      }
    }

    int ans = 0;
    for(int i = 1; i <= n; ++i){
      if(dist[i] == INT_MAX) return -1; // unreachable node
      ans = max(ans, dist[i]);
    }
    return ans;
  }
};
