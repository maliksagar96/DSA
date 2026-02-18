#include <iostream>
#include <vector>

using namespace std;

int main() {

  int lenght, breadth;

  cin >> lenght;
  cin >> breadth;

  int area = lenght * breadth;


  if(area %2 != 0) area = area-1;

  cout << area/2 << endl;


  return 0;
}