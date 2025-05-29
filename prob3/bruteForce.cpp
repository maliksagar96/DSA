#include <iostream> 
using namespace std;

class Solution {
  public:
      int lengthOfLongestSubstring(string s) {
        cout<<s[0] - 'a'<<endl;
        cout<<endl;
        return 0;
      } 
  };

int main() {

  Solution sol;
  string s =  "abzabcbb";
  sol.lengthOfLongestSubstring(s);

  return 0;
}