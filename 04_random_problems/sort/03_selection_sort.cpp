#include <iostream>
#include <vector>

using namespace std;

int main() {

  // vector<int> a = {4,1,8,5,2,19, 12, 27, 0, -2, 22, 9, 11};
  vector<int> a = {4,1,8,5,2};
  int sz = a.size();
  
  int min = a[0];
  

  for(int j = 0;j<sz-1;j++) {
    int minindex = j;  
    for(int i = j+1; i<sz; i++) {
      if(a[i] < a[minindex]) {
        minindex = i;
      }           
    }

    int temp = a[j];
    a[j] = a[minindex];
    a[minindex] = temp;    
  }
    
  for(int i = 0;i<sz;i++) {
    cout<<a[i]<<endl;
  }

  return 0;
}