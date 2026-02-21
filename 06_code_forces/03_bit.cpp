#include <iostream>

using namespace std;

int main() {

    int instances;
    cin >> instances;
    string input;
    int x = 0;
    for(int i = 0;i<instances;i++) {
        cin >> input;
        if(input == "X++") x++;
        else if(input == "X--") x--;
        else if(input == "++X") x++;
        else --x;
    }

    cout << x << endl;

    

    return 0;
}