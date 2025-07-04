/*

Do problem 242 before this. The logic is simple and not that tricky. 
use raw array instead of vector to reduce the over head. 

*/

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
      if(ransomNote.size() > magazine.size())
        return false;
      
        // Use raw array instead of vector<int> or unordered_map>char, int> to reduce overhead.
        int s_map[26] = {0};

        for(int i = 0;i<magazine.size();i++) {          
          s_map[int(magazine[i] - 'a')]++;
        }

        for(int i = 0;i<ransomNote.size();i++) {
          s_map[int(ransomNote[i] - 'a')]--;
          if(s_map[int(ransomNote[i] - 'a')] < 0){
            return false;
          }
        }
        return true;

    }
};

int main() {

  Solution sol;
  string ransomNote ="bg";
  string magazine = "efjbdfbdgfjhhaiigfhbaejahgfbbgbjagbddfgdiaigdadhcfcj";

  cout<<sol.canConstruct(ransomNote, magazine)<<endl;
  

  return 0;
}