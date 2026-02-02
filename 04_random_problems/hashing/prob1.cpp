/*
Since hashing will be used multiple times and I don't have good grasp of application of hashing hence I am
creating a separate folder to understand hashing by doing a simple set of problems. 

Here is the problem, 

---------------------------------

**Problem: Find the First Non-Repeating Character**
Given a string `s`, find the **first character** that does **not repeat**, and return its index. If all characters repeat, return `-1`.

**Example:**
Input: `"leetcode"`
Output: `0`
(because `'l'` is the first non-repeating character)

Input: `"loveleetcode"`
Output: `2`
(because `'v'` is the first non-repeating character)

Input: `"aabb"`
Output: `-1`

**Constraints:**

* `1 <= s.length <= 10⁵`
* `s` contains only lowercase English letters.

---------------------------------------
*/

#include <iostream> 
#include <vector> 
#include <unordered_map>

using namespace std;

void vector_hashing(string s) {
  vector<int> hashMap(26, 0);

  for(int i = 0;i<s.size();i++) {
    hashMap[s[i] - 'a']++;
  }

  for(int i = 0;i<s.size();i++) {
    if(hashMap[s[i] - 'a'] == 1) {
      cout<<"The first non repeating character is "<<s[i]<<" with index = "<<i<<endl;
      exit(0);

    } 
  }

  cout<<"All characters are repeating."<<endl;
}

void unordered_hashing(string s) {

  unordered_map<char, int> hashMap;

  for(char c:s) {
    hashMap[c]++;
  }

  for(int i = 0;i<s.size();i++) {
    if(hashMap[s[i]] == 1) {
      cout<<"The first non repeating character is "<<s[i]<<" with index = "<<i<<endl;
      exit(0);

    } 
  }

  cout<<"All characters are repeating."<<endl;

}

int main() {

  string s =  "aabzb";  
  // vector_hashing(s);
  unordered_hashing(s);


  return 0;
}