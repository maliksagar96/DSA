#include <iostream> 
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    string input;
    cin >> input;

    vector<char> nums;
    for(char c:input) {
        if(c != '+') nums.push_back(c);
    }

    sort(nums.begin(), nums.end());

    for(int i = 0;i<nums.size();i++) {
        cout<<nums[i];
        if(i != nums.size()-1) cout<<"+";
    }

    return 0;
}