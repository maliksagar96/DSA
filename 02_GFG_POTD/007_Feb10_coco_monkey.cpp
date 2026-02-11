/*

Koko is given an array arr[], where each element represents a pile of bananas. She has exactly k hours to eat all the bananas.

Each hour, Koko can choose one pile and eat up to s bananas from it.

    If the pile has atleast s bananas, she eats exactly s bananas.
    If the pile has fewer than s bananas, she eats the entire pile in that hour.

Koko can only eat from one pile per hour.

Your task is to find the minimum value of s (bananas per hour) such that Koko can finish all the piles within k hours.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
  public:
    int kokoEat(vector<int>& arr, int k) {
      // Code here

      int upperValue = *std::max_element(arr.begin(), arr.end());
      int lowerValue = 1;

      //Binary Logic
      while(upperValue > lowerValue) {                
        
        int mid = lowerValue + (upperValue - lowerValue)/2;
        if(works(arr, k, mid)) {
          upperValue = mid;
        }
        else {
          lowerValue = mid+1;
        }
      }

      return lowerValue;
    }

    bool works(vector<int>& arr, int k, int val) {
      int hoursUsed = 0;
      for(int i = 0;i<arr.size();i++) {
        hoursUsed += (arr[i] + val - 1) / val;
      }
      if(hoursUsed <= k) return true;

      return false;
    }
};

int main() {

  vector<int> arr1 = {5, 10, 3};
  int k1 = 4;

  vector<int> arr2 = {5, 10, 15, 20};
  int k2 = 7;

  Solution sol;

  cout << "Test Case 1 = "<<sol.kokoEat(arr1, k1) << endl;
  cout << "Test Case 1 = "<<sol.kokoEat(arr2, k2) << endl;



  return 0;
}