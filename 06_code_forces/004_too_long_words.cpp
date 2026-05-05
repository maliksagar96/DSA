#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int numWords;
    cin >> numWords;

    vector<string> allWords(numWords);

    for (int i = 0; i < numWords; i++) {        
        cin >> allWords[i];        
    
        if(allWords[i].size() > 10) {
            int sz = allWords[i].size();
            allWords[i] = allWords[i][0] + to_string(sz-2) + allWords[i][sz-1];
        }        
    }

    for(auto word:allWords) {
        cout << word << endl;
    }
    

    return 0;
}