#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {

    string s1;
    vector<bool> freq(26, false);

    cin >> s1;

    for(int i = 0;i<s1.size();i++) {
        freq[s1[i] - 'a'] = true;
    }

    int count;
    for(int i = 0;i<26;i++) {
        if(freq[i]) count++;
    }


    if(count %2 == 0) {
        cout << "CHAT WITH HER!\n";
    }

    else {
        cout << "IGNORE HIM!\n";
    }

    return 0;
}