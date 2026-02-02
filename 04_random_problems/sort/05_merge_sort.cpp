#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int> &a, int left, int mid, int right) {
  
  vector<int> temp;
  int i = left;
  int j = mid+1;

  while(i<=mid && j<=right) {
    if(a[i] <= a[j]) temp.push_back(a[i++]);      
    else temp.push_back(a[j++]);
  }

  for(int idx = i;idx<=mid;idx++) {
    temp.push_back(a[idx]);
  }

  for(int idx = j;idx<=right;idx++) {
    temp.push_back(a[idx]);
  }

  for(int i = left;i<=right;i++) {
    a[i] = temp[i-left];
  }

}

void mergesort(vector<int> &a, int left, int right) {

  if(left >= right) {
    return;
  }

  int mid = left + (right-left)/2;
  mergesort(a, left, mid);
  mergesort(a, mid+1, right);
  merge(a, left, mid, right);

}

int main() {

  vector<int> a = {4, 1, 8, 5, 2, 19, 12, 27, 0, -2, 22, 9, 11};
  // vector<int> a = {4,1,8,5,2};
  int sz = a.size();

  mergesort(a, 0, sz-1);

  for(int i = 0;i<sz;i++) {
    cout<<a[i]<<endl;
  }  

  return 0;
}