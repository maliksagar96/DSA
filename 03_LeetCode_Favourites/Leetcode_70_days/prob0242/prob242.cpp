#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size() != t.size()) {
        return false;
      }

      vector<int> s_map(26, 0);
      for(int i = 0; i < s.size(); i++) {
        s_map[s[i] - 'a']++;
        s_map[t[i] - 'a']--;
      }
    
      for(int i = 0; i < 26; i++) {
        if(s_map[i] != 0){
          return false;
        }
      }
      return true;
    }
};

int main() {

  return 0;
}