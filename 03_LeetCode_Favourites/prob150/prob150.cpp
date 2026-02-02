#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> result;
      
      for(int i = 0;i<tokens.size();i++) {
        if(tokens[i] == "+") {
          int first = result.top();
          result.pop();
          int second = result.top();
          result.pop();

          result.push(second + first);

        }

        else if (tokens[i] == "-") {
          int first = result.top();
          result.pop();
          int second = result.top();
          result.pop();

          result.push(second - first);
        }

        else if(tokens[i] == "*") {
          int first = result.top();
          result.pop();
          int second = result.top();
          result.pop();

          result.push(second * first);
        }

        else if(tokens[i] == "/") {
          int first = result.top();
          result.pop();
          int second = result.top();
          result.pop();

          result.push(second / first);
        }

        else{
          result.push(stoi(tokens[i]));
        }
      }

      return result.top();
      
    }
};

int main() {

  
}