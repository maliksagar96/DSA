#include <iostream>
#include <vector>

using namespace std;

int main() {

  // vector<int> a = {4,1,8,5,2,19, 12, 27, 0, -2, 22, 9, 11};
  vector<int> a = {4,1,8,5,2};
  int sz = a.size();

  int key = a[1];
  int index = 1;

  for(int j = 1;j<sz;j++) {
    key = a[j];    
    index = j-1;

    while(a[index] > key && index >= 0)  {
      a[index+1] = a[index];
      index--;
    }

    a[index+1] = key;
  }
  
    
  for(int i = 0;i<sz;i++) {
    cout<<a[i]<<endl;
  }

  return 0;
}