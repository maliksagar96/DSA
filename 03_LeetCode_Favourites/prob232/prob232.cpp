/**

	This is a simple logic. We have to use 2 stacks. 
	Now the key idea is that if you see a stack the objects are first in last out. But if you now transfer the whole stack from top to bottom to a different stack then it acts like a queue. 
	That's the key idea.

*/

#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
	stack<int> in, out;

	void transfer() {
		while (!in.empty()) {
			out.push(in.top());
			in.pop();
		}
	}

public:
	void push(int x) {
			in.push(x);
	}

	int pop() {
		if (out.empty()) transfer();
		int val = out.top();
		out.pop();
		return val;
	}

	int peek() {
		if (out.empty()) transfer();
		return out.top();
	}

	bool empty() {
		return in.empty() && out.empty();
	}
};

int main() {
    MyQueue q;
    q.push(1);
    q.push(2);
    cout << q.peek() << "\n"; // 1
    cout << q.pop() << "\n";  // 1
    cout << q.empty() << "\n"; // 0 (false)
}
