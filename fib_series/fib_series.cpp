/*
    Well there are 2 approaches. 
    1) The first one is using memoisation. The current fibonacci series is remembering the last result. But this is both time and space complexity of 1. 
		2) The second method is using a trick. It is optimal for both time and space. Time complexity is O(n) and space complexity is O(1).
		A major warning is that internet is full of solutions with names for variable like a and b. Don't use that. 
		3) This is the least optimal approach for time as well as space. The call stack will grow as O(n). For time it is O(2^n). 
*/


#include <iostream>
#include <vector>   

using namespace std;

int fibonacci(int n) {

    vector<int> fib_series(n, 0);
    fib_series[0] = 0;
    fib_series[1] = 1;            
    for(int i = 2;i<n;i++) {
			fib_series[i] = fib_series[i-1] + fib_series[i-2];        
    }

    return fib_series[n-1];
}

int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int prev = 0;
    int curr = 1;
    int next;
    for (int i = 2; i <= n; i++) {
        next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}


int recursive_fibonacchi(int n) {
    if(n <= 1) return n;        
    return fibonacci(n-1) + fibonacci(n-2);    
}

int main() {

    cout<<fib(10)<<endl;
    return 0;
}