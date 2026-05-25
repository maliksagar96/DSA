#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    if(strs.size() == 0) return {};    
    vector<vector<string>> result;

    vector<bool> visited(strs.size(), false);

    for(int i = 0;i<strs.size();i++) {
      if(visited[i]) continue;

      vector<string> group;
      group.push_back(strs[i]);

      for(int j = i+1;j<strs.size();j++) {
        if(isAnagram(strs[i], strs[j]) && !visited[j]) {
          visited[j] = true;        
          group.push_back(strs[j]);
        }
      }
      visited[i] = true;
      result.push_back(group);
    }

    return result;

  }

  bool isAnagram(string s, string t) {
    if(s.size() != t.size()) return false;
    int cnt[26] = {0};
    for(char c : s) cnt[c - 'a']++;
    for(char c : t) cnt[c - 'a']--;
    for(int x : cnt) if(x != 0) return false;
    return true;
  }

};

int main() {

  return 0;
}