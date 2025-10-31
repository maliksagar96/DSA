#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
  unordered_map<char, string> phone = {
    {'2', "abc"}, {'3', "def"}, {'4', "ghi"},
    {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
    {'8', "tuv"}, {'9', "wxyz"}
  };

  vector<string> result;

  vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};  
    string current;
    backtrack(0, digits, current);
    return result;
  }

private:
  void backtrack(int index, const string &digits, string &current) {
    if (index == digits.size()) {
      result.push_back(current);
      return;
    }

    for (char c : phone[digits[index]]) {
      current.push_back(c);
      backtrack(index + 1, digits, current);
      current.pop_back(); // backtrack
    }
  }
};

int main() {
  Solution sol;
  vector<string> combos = sol.letterCombinations("234");
  for (auto &s : combos)
    cout << s << endl;
  return 0;
}
