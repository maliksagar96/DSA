#include <iostream>

using namespace std;

int main() {

    int input;
    cin >> input;

    int counter = 1;
    while(input > 5) {
        input = input-5;
        counter++;
    }

    cout << counter << endl;

    return 0;
}