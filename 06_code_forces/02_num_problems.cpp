#include <iostream>
#include <vector>

using namespace std;

int main() {

    int numProblems;
    cin >> numProblems;
    int outPut=0;

    int input[3];

    for(int i = 0;i<numProblems;i++) {
        for(int j = 0;j<3;j++) {
            cin >> input[j];
        }
        int sum = input[0] + input[1] + input[2];
        if(sum >= 2) outPut++;
    }

    cout << outPut << endl;

    return 0;
}