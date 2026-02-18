#include <iostream>

using namespace std;

int main() {

  int targetCol, targetRow;

  for(int i = 0;i<5;i++) {
    for(int j = 0;j<5;j++) {
      int num;
      cin >> num;
      if(num == 1) {
        targetRow = i;
        targetCol = j;
      }  
    }    
  }

  cout << abs(targetCol - 2) + abs(targetRow - 2) << endl;

  return 0;
}