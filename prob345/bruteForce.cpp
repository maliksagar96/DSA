/*
This is a simple 2 pointer problem. 
The first step is to separate the vowels out
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  string reverseVowels(string s) {
    vector<pair<int, char>> vowels;
    for(int i = 0;i<s.size();i++) {
      char ch = tolower(s[i]);
      if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        vowels.push_back({i, s[i]});
      }
    }
    
    int left = 0, right = vowels.size()-1;

    // for(int i = 0;i<vowels.size();i++) {
    //   cout<<"vowels[first] = "<<vowels[i].first<<endl;
    // }

    while(left < right) {
      swap(s[vowels[left].first], s[vowels[right].first]);
      cout<<"left = "<<left<<endl;
      cout<<"s[vowels[left].first] = "<<s[vowels[left].first]<<endl;
      left++;
      right--;
    }
    return s;
  }
};


int main() {

  Solution sol;
  string s = "leetcode";
  cout<<sol.reverseVowels(s)<<endl;

}