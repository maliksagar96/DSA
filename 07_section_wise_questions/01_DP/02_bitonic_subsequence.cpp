#include <iostream>
#include <vector>

using namespace std;

int main() {
	
	vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};

	for(int x:arr) {
		cout << x << " ";
	}

	cout << endl;
	int n = arr.size();

	// for(int i = 0; i < n; i++)
	// 	cin >> arr[i];

 	vector<int> lis(n, 1);
	vector<int> lds(n, 1);

	// LIS
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i])
			{				
				lis[i] = max(lis[i], lis[j] + 1);
			}
		}
	}

	// LDS
	for(int i = n - 1; i >= 0; i--)
	{
		for(int j = n - 1; j > i; j--)
		{
			if(arr[j] < arr[i])
			{
				lds[i] = max(lds[i], lds[j] + 1);
			}
		}
	}

	int answer = 0;

	for(int i = 0; i < n; i++)
	{
		answer = max(answer, lis[i] + lds[i] - 1);
	}

	cout << answer << endl;

	return 0;
}