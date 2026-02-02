/*

  Given a string s, find the length of the longest substring without duplicate characters.

  Example 1:

  Input: s = "abcabcbb"
  Output: 3
  Explanation: The answer is "abc", with the length of 3.
  Example 2:

  Input: s = "bbbbb"
  Output: 1
  Explanation: The answer is "b", with the length of 1.
  Example 3:

  Input: s = "pwwkew"
  Output: 3
  Explanation: The answer is "wke", with the length of 3.
  Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

*/
/*

This is the first Leet code question for which I am finding it difficult to code the brute force version as well. Otherwise bruteforce till now 
seemed very easy. 

Now how do i even tell the algo, it went from case to case. 
As and when a faulty case occured i just patched my code up accordingly and the time my code took is way too much. 
What i would do is tell the general algo and then I will tell the fixes to the bugs that occured for particular cases. 

Algo:
Add the first char of the string to a hashmap.
Then we will traverse the string and check if any character is repeating that is already in the hashmap. 
If one such character is found then save the lenght as size of this hashmap. If maxSize is smaller then the lenght hashMap, maxSize = hashMap.size()
And then reset the value of i to the index where the first ever case of the current character was found, meaning nullyfying the string before it. 
THat part of the string will have no effect on the maxSize. Repeating this process till we traverse the whole string. 


The cases where I got stuck:
1) s ="", i.e. empty string. 
    Fix => if (s.empty()) return 0;

2) s = "dvdf", 
Fix => i = string1[string(1, s[i])];

*/

#include <iostream> 
#include <unordered_map> 

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
      if (s.empty()) return 0;

      unordered_map<char, int> string1;
      int maxSize = 1;

      string1[s[0]] = 0;

      for (int i = 1; i < s.size(); i++) {
        if (string1.find(s[i]) != string1.end()) {
          if (string1.size() > maxSize) maxSize = string1.size();
            i = string1[s[i]];
            string1.clear();
            continue;
        }
        string1[s[i]] = i;
      }

      if (string1.size() > maxSize) maxSize = string1.size();
      return maxSize;
  }
};

int main() {

  Solution sol;
  string s ="dvdf";  
  cout<<"MaxSize = "<<sol.lengthOfLongestSubstring(s)<<endl;

  return 0;
}