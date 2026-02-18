#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {

  string odd = "I hate ";
  string even = "I love ";

  string fullString;

  int input;

  cin >> input;

  for(int i = 1;i<input;i++) {
    if(i%2 == 0) fullString +=  even;
    else fullString += odd; 

    fullString +=  "that ";

  }

  if(input % 2 != 0) fullString += "I hate it" ;  
  else fullString += "I love it";
  
  cout << fullString << endl;

  return 0;
}