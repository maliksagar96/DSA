#include <iostream>
#include <cctype>

using namespace std;

int main() {

    string input;
    cin >> input;

    char c = std::toupper(static_cast<unsigned char>(input[0]));
    input[0] = c;

    cout << input << endl;

    return 0;
}