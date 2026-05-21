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
  
  bool isVowel(char ch) {
    if(ch == 'a' || ch == 'e' || ch == 'i' || ch = 'o' || ch = 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;

    return false;
  }

  string reverseVowels(string s) {
    
    int n = s.size();
    int left = 0, right = n-1;

    while(left < right) {
      if(!isVowel(s[left])) left++;
      else if(!isVowel(s[right])) right--;
      else {
        swap(s[left], s[right]);
        left++;
        right--;
      } 
    }

    return s;
  }
};


int main() {

  Solution sol;
  string s = "leetcode";
  cout<<sol.reverseVowels(s)<<endl;

}