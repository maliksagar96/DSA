/**
Actually there is a version of this code I used in the brute force and the take_2.cpp. 
Those solutions i though would be faster because I thought hashmaps are faster then vectors. But vectors are faster. 
Hashmaps would have overhead of hashing and then accessing the keys.
By continuous practice of hashmaps I developed a habit that hashmaps are faster, which is not the case.

In this case vector would give a much faster result. it won't beat hashmap on memory however. 

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
      if(s.size() != t.size()) {
        return false;
      }

    unordered_map<char, int> string_s;
    unordered_map<char, int> string_t;

      for(int i = 0;i<s.size();i++) {
        string_s[s[i]]++;
        string_t[t[i]]++;
      }

      //compare the 2 hashmaps.
      if(string_s == string_t) {return true;}
      else{return false;}

  
    }
};

int main() {

  return 0;
}