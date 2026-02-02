/*
  A typical 2 pointer problem. 
  Start one pointer from the left and the other from right.
*/

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
      s = cleanString(s);
      cout<<s<<endl;      
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

    string cleanString(const string& input) {
      string result;
      for (char c : input) {
        if (isalnum(static_cast<unsigned char>(c))) {
            result += tolower(static_cast<unsigned char>(c));
        }
      }
      return result;
    }    
};

int main(){
  Solution sol;
  string s = "A man, a plan, a canal: Panama";
  cout << sol.isPalindrome(s) << endl;

  return 0;
}