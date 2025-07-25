/*

  The array is reduced to size of 1, then the left and right are already sorted. 
  Then we take arrays of size 2 and 1 and we work our way up from there. 
  Then of size 2 and 2 and so on.
  This sorts the arrays. 
  And then finally the sorted arrays are mergerd. 
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

void merge_sort(vector<int>& a) {
  if(a.size() <=1) return;
  
  int mid = a.size()/2;
  vector<int> left(a.begin(), a.begin() + mid);
  vector<int> right(a.begin() + mid, a.end());

  merge_sort(left);
  merge_sort(right);

  a.clear();
  merge_arrays(left, right, a);

}

int main() {
  vector<int> a = {4, 2, 6, 1, 3, 9, 7};
  merge_sort(a);
  
  for (int x : a) cout << x << endl;
  return 0;
}