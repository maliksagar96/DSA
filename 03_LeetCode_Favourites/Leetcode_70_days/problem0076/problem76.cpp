#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

	bool isSufficient(vector<int>& freq_T, vector<int>& freq_slid_window) {
		for(int i = 0;i<26;i++) {
			if(freq_T[i] != freq_slid_window) return false;
		}
		return true;
	}

	string minWindow(string s, string t) {
		vector<int> freq_T(26,0);
		vector<int> freq_slid_window(26, 0);
		
	}
};

int main() {

	return 0;
}