#include <iostream>
#include <stack>

using namespace std;

class myQueue {

	stack<int> myStack;

public:

	myQueue() {
	}

	void enqueue(int x) {

		stack<int> temp;

		while(!myStack.empty()) {
			temp.push(myStack.top());
			myStack.pop();
		}

		myStack.push(x);

		while(!temp.empty()) {
			myStack.push(temp.top());
			temp.pop();
		}
	}

	void dequeue() {

		if(!myStack.empty()) {
			myStack.pop();
		}
	}

	int front() {

		if(myStack.empty()) {
			return -1;
		}

		return myStack.top();
	}

	int size() {

		return myStack.size();
	}
};



int main() {

    return 0;
}