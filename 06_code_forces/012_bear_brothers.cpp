#include <iostream>

using namespace std;

int main() {

    int limak, bob;

    cin >> limak;
    cin >> bob;

    int counter = 0;

    while(limak <= bob) {
        limak = 3 * limak;
        bob = 2 * bob;
        counter++;
    }

    cout << counter << endl;

    return 0;
}