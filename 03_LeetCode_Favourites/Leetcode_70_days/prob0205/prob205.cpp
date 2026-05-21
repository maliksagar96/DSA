/*

Another Easy problem using hashmap. 
The only tricky thing here is that check mapping of characters from s to t and t to s both. Initially I thought one way should be enough. 

If you are still not able to do this easy hashmap problem then follow the 70 days DSA plan properly. By this point you should be able to 
code these kind of problems with ease.

*/


#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
	bool isIsomorphic(string s, string t) {
		if (s.size() != t.size()) {
			return false;
		}

		vector<int> uniqueID_s(128, 0);
		vector<int> uniqueID_t(128, 0);

		for(int i = 0;i<s.size();i++) {			
			if(uniqueID_s[s[i]] != uniqueID_t[t[i]]) 
			return false;
			uniqueID_s[s[i]] = i+1;
			uniqueID_t[t[i]] = i+1;
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