/*

This is the first stack problem. A good problem to get started with stacks but should have basic knowledge of hashmaps first. 

Can't get an easier problem then this while understanding stacks. 

The return statement at the end is due to an edge case, like s = '((' or '[['. Otherwise logic is simple. 

*/


#include <iostream>
#include <unordered_map>

using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<char> brkstk;
    if(s.size() == 1) return false;
    if(s.size() == 0) return true;
    unordered_map<char, char> brackets = {{')', '('}, {']', '['}, {'}','{'}};

    for(int i = 0;i<s.size();i++) {
      char c = s[i];
      if(brackets.count(c)){
          if(brkstk.empty() || brkstk.top() != brackets[c]) {
            return false;
          }
        brkstk.pop();
      }
      else{
        brkstk.push(c);
      }      
    }
    return brkstk.empty();
  }
};

int main() {

  char b = ')';
  cout<<int(b)<<endl;
}