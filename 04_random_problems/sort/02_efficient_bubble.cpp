/*
  Bubble sort can also be made efficient. 
  We can break the loop if the there was no element swapped in this pass. 
  If there was no element swapped in this pass that means the array is already sorted.
*/

#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> a = {4,1,8,5,2,19, 12, 27, 0, -2, 22, 9, 11};
  int sz = a.size();
  
  for(int j= 0;j<sz;j++) {
    bool swap  = false;
    for(int i = 0;i<sz-1-j;i++) {
      int temp;
      
      if(a[i] > a[i+1])  {
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
        swap = true;
      }
    }
    if(!swap) break;
  }
  
  for(int i = 0;i<sz;i++) {
    cout<<a[i]<<endl;
  }

  return 0;
}