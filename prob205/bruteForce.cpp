/*

Another Easy problem using hashmap. 
The only tricky thing here is that check mapping of characters from s to t and t to s both. Initially I thought one way should be enough. 

If you are still not able to do this easy hashmap problem then follow the 70 days DSA plan properly. By this point you should be able to 
code these kind of problems with ease.

*/


#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }

        unordered_map<char, char> map_s_t;
        unordered_map<char, char> map_t_s;
        map_s_t[s[0]] = t[0];
        map_t_s[t[0]] = s[0];

        for (int i = 1; i < s.size(); i++) {
            if (map_s_t.find(s[i]) != map_s_t.end()) {
                if (map_s_t[s[i]] != t[i]) {
                    return false;
                }
            } else {
                map_s_t[s[i]] = t[i];
            }

            if (map_t_s.find(t[i]) != map_t_s.end()) {
                if (map_t_s[t[i]] != s[i]) {
                    return false;
                }
            } else {
                map_t_s[t[i]] = s[i];
            }
        }
        return true;
    }
};

int main(){

  Solution sol;
  string s = "egg";
  string t = "add";
  cout<<sol.isIsomorphic(s,t)<<endl;
  return 0;
}