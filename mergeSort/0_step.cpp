/*
  This is the way to learn merge sort. 
  The 0th step is to merge 2 sorted arrays. 
  This code is as simple as any c++ code can be. 
*/

#include <iostream>
#include <vector>
using namespace std;

void merge_arrays(vector<int>& a, vector<int>& b, vector<int>& c) {
  int n = 0, m = 0;

  while(n < a.size() && m < b.size()) {
    if(a[n] < b[m]) c.push_back(a[n++]);
    else c.push_back(b[m++]);
  }

  while(n < a.size()) c.push_back(a[n++]);
  while(m < b.size()) c.push_back(b[m++]);

}

int main() {
  vector<int> a = {1, 3, 5, 6};
  vector<int> b = {2, 3, 4, 7, 9};
  vector<int> c;

  merge_arrays(a, b, c);
  
  for(int i = 0; i < c.size(); i++) {
    cout << c[i] << endl;
  }

  return 0;
}
