#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
      int left = s.size()/2, right= s.size()/2;
      if(s.size() % 2 != 0) {
        left = (s.size() - 1)/2 - 1;
        right = (s.size() + 1)/2 - 1;
      }
      
      while(left < right) {
        
      }
    }
};

int main(){
  Solution sol;
  string s = "babad";
  string result = sol.longestPalindrome(s);
  cout << result << endl;

  return 0;
}