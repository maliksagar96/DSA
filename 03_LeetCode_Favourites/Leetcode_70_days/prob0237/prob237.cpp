#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		if(!node) return;

		node->val = node->next->val;
		ListNode* nextNode = node->next;
		node->next = node->next->next;
		delete temp;

	}
};