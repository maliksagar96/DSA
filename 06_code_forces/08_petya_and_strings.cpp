#include <iostream>
#include <algorithm>
#include <cctype>
#include <string>

using namespace std;

int main() {

    string s1;
    string s2;

    cin >> s1;
    cin >> s2;

    transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char c){return tolower(c);});
    transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char c){return tolower(c);});

    if(s1 == s2) {
        cout << "0" << endl;
    }

    else if (s1 > s2) {
        cout << "1" << endl;
    }

    else {
        cout << "-1" <<endl;
    }
    

    return 0;
}