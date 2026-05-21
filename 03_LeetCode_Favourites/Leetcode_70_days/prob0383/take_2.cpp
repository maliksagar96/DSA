#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    if(ransomNote.size() > magazine.size()) return false;

    vector<int> freq(26, 0);
    for( char ch:ransomeNote) {
      freq[ch - 'a']++;
    }

    for(char ch:magazine) {
      freq[ch-'a']--;
      if(freq[ch - 'a'] < 0) 
      return false;
    }

    return true;

  }
};

int main() {

  Solution sol;

  string magazine =

      return 0;
}