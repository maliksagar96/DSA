/*
Code
Testcase
Test Result
Test Result
5. Longest Palindromic Substring
Medium
Topics
premium lock icon
Companies
Hint
Given a string s, return the longest palindromic substring in s.

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      vector<string> pal;
      string longestString = s.substr(0,1);
      int sz = 1;
      for(int i=0;i<s.size();i++) {
        for (int j = 0; j < s.size(); j++) {
         if (j + sz <= s.size()) {
          string cut_string = s.substr(j, sz);
          if (isPalindrome(cut_string)) {
            if (cut_string.size() > longestString.size())
                longestString = cut_string;
        }
    }
}
        sz++;
      }  
      return longestString;    
    }

     bool isPalindrome(string s) {
      
      int left = 0, right = s.size()-1;
      while(left < right) {
        if(s[left] == s[right]) {
          left++;
          right--;
        }
        else{
          return false;        
        }
      }
      return true;
    }
    
};

int main() {
  Solution sol;

  string  s = "babad";

  cout<<"Longest = "<<sol.longestPalindrome(s)<<endl;

  return 0;
}