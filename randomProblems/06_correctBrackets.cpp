#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {

  string s = "([{}])";   // test case
  // string s = "(]";    // try this later
  // string s = "((())"; // try this later

  // TODO:
  // Use a stack to check if the brackets are valid
  // Print "Valid" or "Invalid"

  stack<char> brackets;

  for(char c:s){
    if(c == "(" || c == "{" || c == "[") {
      brackets.push(c);
    }
    else if(brackets.empty()) {
      cout<<"Invalid stack of brackets.\n";
      break;
    }

    char top = brackets.top;
    brackets.pop();
    if((c == ")" && top != "(") ||
        (c == "]" && top != "[") ||
        (c == "}" && top != "{") ||
      ) {
      cout<<"Invalid stack of brackets.\n";
      break;
    }

  }

  return 0;
}
