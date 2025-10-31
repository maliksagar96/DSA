#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
      stack<char> result;
      
      for(int i = 0;i<s.size();i++) {
        if(s[i] == ']') {
          int reverse_counter = i;
          while(s[reverse_counter] != '[') {
            reverse_counter--;
          } 
        }

        result.push(s[i]);

      }
      
      
      return s;
    }
};



int main() {
  
    Solution sol;



    sol.decodeString(s);

    return 0;
}
