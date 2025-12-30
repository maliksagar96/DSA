#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isAnagram(string s, string t) {
    unordered_map <char, int> hashmap;

    int sz = s.size();
    if(sz != t.size()) return false;

    for(int i = 0;i<sz;i++) {
      hashmap[s[i]]++;
      hashmap[t[i]]--;
    }

    for(auto n:hashmap) {
      if(n.second != 0) return false;
    }

    return true;
  }
};

int main() {

  return 0;
}