/*
  In every pass the largest entry is shifted to the end of the array.
  Hence we don't need to check the last entry again. Then we don't need to check the second last entry and so on ...
*/


#include <iostream>
#include <vector>

using namespace std;

int main() {

  vector<int> a = {4,1,8,5,2};
  int sz = a.size();

  for(int j= 0;j<sz-1;j++) {
    for(int i = 0;i<sz-j-1;i++) {
      int temp;
      if(a[i] > a[i+1])  {
        temp = a[i];
        a[i] = a[i+1];
        a[i+1] = temp;
      }
    }
  }
  

  for(int i = 0;i<sz;i++) {
    cout<<a[i]<<endl;
  }

  return 0;
}