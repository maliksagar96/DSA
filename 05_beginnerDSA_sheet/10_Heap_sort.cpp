#include <iostream>
#include <vector>

using namespace std;

/*
If an element is present at the index i then its left child is at 2i+1 and right child is at 2i+2. 
Last leaf node is at int lastNonLeaf = n/2 - 1;
*/

class Solution {
  public:
    // Function to sort an array using Heap Sort.

	void heapify(vector<int>& arr, int leafIndex, int n) {
		if(n < 0) return;
		int largest = leafIndex;

		int left = 2*leafIndex + 1;
		int right = 2*leafIndex + 2;
		
		//Correcting the last nonleaf entry
		//Compare left and right child.
		if(left < n && arr[left] > arr[largest]){
			largest = left;
		}
		
		if(right < n && arr[right] > arr[largest]) {
			largest = right;
		}

		if(largest != leafIndex) {
			swap(arr[largest], arr[leafIndex]);
			heapify(arr, largest, n);
		}
	}

	void heapSort(vector<int>& arr) {
		// code here
		int n = arr.size();
		int lastNonLeaf = n/2 - 1;
		
		//Now this builds a valid max heap. This is not enough.
		for(int leafIndex = lastNonLeaf;leafIndex >= 0; leafIndex--) {
			heapify(arr, leafIndex, n);
		}

		for(int i = n-1;i>0;i--) {
			swap(arr[0], arr[i]);
			heapify(arr, 0, i);
		}
					
	}
};

int main() {

    return 0;
}