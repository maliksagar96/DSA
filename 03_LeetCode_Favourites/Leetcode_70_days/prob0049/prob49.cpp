#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> group;
    vector<vector<string>> result;

    for(string s:strs) {
      string key = s;
      sort(key.begin(), key.end());
      group[key].push_back(s);
    }
  
    for(auto [key, value]: group) result.push_back(value);


    return result;
  }
};


int main() {

  return 0;
}